#include <Kraken/Engine/KRComponent.h>
#include <stdexcept>
#include <Kraken/Engine/BaseEntity.h>
#include <Kraken/Engine/BaseChapter.h>

using namespace kraken;

kraken::KRComponent::KRComponent(KREntity* entity) : m_entity(entity) {
	ASSERT(dynamic_cast<KREntity*>(entity));
}

kraken::KRComponent::~KRComponent() {}

KREntity* kraken::KRComponent::getEntity() {
	return m_entity;
}