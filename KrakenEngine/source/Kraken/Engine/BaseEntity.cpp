#include "BaseEntity.h"
#include "BaseEntityComponentManager.h"

using namespace kraken;

BaseEntity::BaseEntity(KREntityHandle handle, KREntityComponentManager* ecManager): m_handle(handle) {
	m_ecManager = ecManager;
}


BaseEntity::~BaseEntity() {}

KREntityHandle kraken::BaseEntity::getHandle() {
	return m_handle;
}

void kraken::BaseEntity::release() {
	static_cast<BaseEntityComponentManager*>(m_ecManager)->destroyEntity(this);
	ReleaseFn(this);
}
