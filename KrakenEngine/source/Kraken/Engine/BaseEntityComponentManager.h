#pragma once

#include <Kraken/Engine/KREntityComponentManager.h>
#include <Kraken/Engine/KREntity.h>
#include "BaseTemplateFactory.h"

#include "BaseEntity.h"
#include <Kraken/Engine/KRComponent.h>
#include <map>

namespace kraken {
	class BaseEntityComponentManager : public kraken::KREntityComponentManager {
	public:
		BaseEntityComponentManager();
		~BaseEntityComponentManager();
		KREntity* createEntity();

		virtual void* createComponentConcrete(KREntity* entity, size_t idComponent, size_t sizeComponent);
		virtual void* getComponentConcrete(KREntity* entity, size_t idComponent);
		virtual void removeComponentConcrete(KREntity* entity, size_t idComponent);

		void destroyEntity(KREntity* entity);

	private:
		KREntityHandle m_id_counter = 0;
		std::map<size_t, std::map<size_t, void*>> m_map_components;

	private:
		BaseTemplateFactory<BaseEntity, KREntityHandle, KREntityComponentManager*> m_entityFactory;
	};
}

