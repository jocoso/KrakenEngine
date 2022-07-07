#pragma once

#include <Kraken/Core/KRCommon.h>
#include <Kraken/Engine/KrakenEngine.h>

namespace kraken {
	// Export dll
	class KR_API KRApplication {

	public:
		KRApplication();
		virtual ~KRApplication();

		virtual void onInit() {};
		virtual void onStop() {};
		virtual void onUpdate() {};

		void run();
		void stop();

		KrakenEngine* getEngine();
	public:
		static KRApplication* get();

	private:
		static KRApplication* m_instance;

	private:
		bool m_isRunning = true;
		KrakenEngine* m_engine = nullptr;
	};
}