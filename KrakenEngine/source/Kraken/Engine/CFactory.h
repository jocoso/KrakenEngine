#pragma once

#include <Kraken/Core/KRCommon.h>
#include <set>
#include "CTemplateFactory.h"
#include "CScene.h"

namespace kraken {
	class CFactory {
	public:
		CFactory();
		~CFactory();
		void release();
		CTemplateFactory<CScene>* getSceneFactory();

	public:
		static void create();
		static CFactory* get();
	private:
		static void destroy();
	private:
		static CFactory* m_instance;

		CTemplateFactoryEx<CScene> m_sceneFactory;
	};
}

