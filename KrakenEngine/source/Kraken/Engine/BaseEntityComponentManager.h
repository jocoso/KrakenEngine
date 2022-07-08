#pragma once

#include <Kraken/Engine/KREntityComponentManager.h>
#include <Kraken/Engine/KREntity.h>
#include "BaseTemplateFactory.h"
#include "BaseEntity.h"

namespace kraken {
	class BaseEntityComponentManager : public kraken::KREntityComponentManager {
	public:
		BaseEntityComponentManager();
		~BaseEntityComponentManager();
		KREntity* createEntity();

	private:
		KREntityHandle m_id_counter = 0;

	private:
		BaseTemplateFactory<BaseEntity, KREntityHandle> m_entityFactory;
	};
}