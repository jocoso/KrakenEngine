#pragma once

#include <Kraken/Engine/KrakenEngine.h>
#include "CScene.h"

namespace kraken {
	class CEngine: public kraken::KrakenEngine {
	private:
		CEngine();
		~CEngine();
		virtual void release() override;

		virtual KRScene* createScene() override;
		virtual ui32 getScenesID() override;

	public:
		static CEngine* create();
	private:
		static void destroy();
	private:
		static CEngine* m_instance;
		CTemplateFactory<CScene> m_sceneFactory;
	};

}