#include "CEntity.h"
using namespace kraken;

CEntity::CEntity(KREntityHandle handle) : m_handle(handle) {}
CEntity::~CEntity() {}

KREntityHandle kraken::CEntity::getHandle() {
	return m_handle;
}

void kraken::CEntity::release() {
	ReleaseFn(this);
}
