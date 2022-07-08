#include "BaseEntityComponentManager.h"
using namespace kraken;

kraken::BaseEntityComponentManager::BaseEntityComponentManager() {}
kraken::BaseEntityComponentManager::~BaseEntityComponentManager() {}

KREntity* kraken::BaseEntityComponentManager::createEntity() {
	auto it = m_id_counter;
	m_id_counter++;
	return m_entityFactory.createResource(it);
}