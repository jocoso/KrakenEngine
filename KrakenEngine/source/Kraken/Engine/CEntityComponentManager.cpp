#include "CEntityComponentManager.h"
using namespace kraken;

kraken::CEntityComponentManager::CEntityComponentManager() {}
kraken::CEntityComponentManager::~CEntityComponentManager() {}

KREntity* kraken::CEntityComponentManager::createEntity() {
	auto it = m_id_counter;
	m_id_counter++;
	return m_entityFactory.createResource(it);
}
