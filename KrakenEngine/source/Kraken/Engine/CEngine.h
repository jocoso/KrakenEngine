#pragma once

#include <Kraken/Engine/KrakenEngine.h>
#include "CFactory.h"

namespace kraken {
	class CEngine: public kraken::KrakenEngine {
	private:
		CEngine();
		~CEngine();
		virtual void release() override;

		virtual KRScene* createScene() override;
		virtual ui32 getScenesID() override;

	public:
		static void create();
		static CEngine* get();
	private:
		static void destroy();
	private:
		static CEngine* m_instance;
	};

}