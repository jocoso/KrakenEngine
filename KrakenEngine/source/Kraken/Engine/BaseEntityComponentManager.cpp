#include "BaseEntityComponentManager.h"
using namespace kraken;

kraken::BaseEntityComponentManager::BaseEntityComponentManager() {}
kraken::BaseEntityComponentManager::~BaseEntityComponentManager() {}

KREntity* kraken::BaseEntityComponentManager::createEntity() {
	auto it = m_id_counter;
	m_id_counter++;
	return m_entityFactory.createResource(it, this);
}

void* kraken::BaseEntityComponentManager::createComponentConcrete(KREntity* entity, size_t idComponent, size_t sizeComponent) {
	void* comp = nullptr;
	auto it = m_map_components.find(entity->getHandle());
	if (it != m_map_components.end()) {
		auto it2 = it->second.find(idComponent);
		if (it2 == it->second.end()) {
			comp = ::malloc(sizeComponent);
			it->second.emplace(idComponent, comp);
		}
	} else {
		comp = ::malloc(sizeComponent);
		std::map<size_t, void*> m;
		m.emplace(idComponent, comp);
		m_map_components.emplace(entity->getHandle(), m);
	}

	return comp;
}

void* kraken::BaseEntityComponentManager::getComponentConcrete(KREntity* entity, size_t idComponent) {
	auto it = m_map_components.find(entity->getHandle());

	if (it != m_map_components.end()) {
		
		auto it2 = it->second.find(idComponent);
		if (it2 != it->second.end()) {
			return it2->second;
		}

	}

	return nullptr;
}

void kraken::BaseEntityComponentManager::removeComponentConcrete(KREntity* entity, size_t idComponent) {
	auto it = m_map_components.find(entity->getHandle());
	if (it != m_map_components.end()) {
		auto it2 = it->second.find(idComponent);
		if (it2 != it->second.end()) {
			KRComponent* comp = (KRComponent*)it2->second;
			delete comp;
			it->second.erase(it2);
		}
	}
}

void kraken::BaseEntityComponentManager::destroyEntity(KREntity* entity) {
	auto it = m_map_components.find(entity->getHandle());
	if (it != m_map_components.end()) {
		auto it2 = it->second.begin();

		while (it2 != it->second.end()) {
			KRComponent* comp = (KRComponent*)it2->second;
			delete comp;
			++it2;
		}
		m_map_components.erase(it);
	}
}