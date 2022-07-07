#pragma once
#include <Kraken/Engine/KRScene.h>
#include "CTemplateFactory.h"
#include "CEntityComponentManager.h"

namespace kraken {
	class CScene : public KRScene, public CTemplateResource<CScene> {
	public:
		CScene();
		~CScene();
		virtual void release() override;
		virtual KREntity* createEntity() override;
	private:
		CEntityComponentManager m_ecManager;
	};
}

