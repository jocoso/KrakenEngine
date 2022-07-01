#pragma once
#include "KrakenEngine/Core/KRCommon.h"

namespace kraken {

	class KRAKEN_API KRApplication {
	public:
		KRApplication();
		virtual ~KRApplication();

		virtual void onInit() {};
		virtual void onStop() {};

		void run();
		void stop();

	public:
		static KRApplication* get();

	private:
		static KRApplication* m_instance;
	private:
		bool m_isRunning = true;
	};
}