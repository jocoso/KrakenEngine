#include "BaseEntity.h"
using namespace kraken;

BaseEntity::BaseEntity(KREntityHandle handle) : m_handle(handle) {}

BaseEntity::~BaseEntity() {}

KREntityHandle kraken::BaseEntity::getHandle() {
	return m_handle;
}

void kraken::BaseEntity::release() {
	ReleaseFn(this);
}