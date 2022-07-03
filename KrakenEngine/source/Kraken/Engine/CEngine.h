#pragma once

#include <Kraken/Engine/KrakenEngine.h>

namespace kraken {
	class CEngine: public kraken::KrakenEngine {
	private:
		CEngine();
		~CEngine();

	public:
		virtual void release() override;
	public:
		static CEngine* create();
	private:
		static void destroy();
	private:
		static CEngine* m_instance;
	};

}