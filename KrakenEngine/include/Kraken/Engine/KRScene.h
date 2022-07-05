#pragma once
#include <Kraken/Core/KRBase.h>

namespace kraken {
	class KRScene {
	public:
		KRScene() {}
		~KRScene() {}
		virtual void release() = 0;
	};
}