#pragma once

#include <Kraken/Engine/KREntityComponentManager.h>
#include <Kraken/Engine/KREntity.h>
#include "CTemplateFactory.h"
#include "CEntity.h"


namespace kraken {
	class CEntityComponentManager : public kraken::KREntityComponentManager {
	public:
		CEntityComponentManager();
		~CEntityComponentManager();
		KREntity* createEntity();

	private:
		KREntityHandle m_id_counter = 0;

	private:
		CTemplateFactory<CEntity, KREntityHandle> m_entityFactory;

	};

}

