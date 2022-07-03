#pragma once

#include <Kraken/Core/KRCommon.h>

namespace kraken {
	class KrakenEngine {
	public:
		KrakenEngine() {}
		~KrakenEngine() {}
		virtual void release() = 0;
	};

	KRAKEN_API KrakenEngine* CreateKrakenEngine();
}