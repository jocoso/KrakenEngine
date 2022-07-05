#pragma once

#include <Kraken/Core/KRCommon.h>
#include <Kraken/Core/KRBase.h>

namespace kraken {
	class KrakenEngine {
	public:
		KrakenEngine() {}
		~KrakenEngine() {}
		virtual void release() = 0;

		virtual KRScene* createScene() = 0;
		virtual ui32 getScenesID() = 0;
	};

	KRAKEN_API KrakenEngine* CreateKrakenEngine();
}