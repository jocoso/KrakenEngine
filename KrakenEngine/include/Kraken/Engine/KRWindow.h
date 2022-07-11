#pragma once
#include <Kraken/Core/KRBase.h>

namespace kraken {
	class KRWindow : public KRBase {
	public:
		KRWindow() {}
		~KRWindow() {}
		virtual void release() = 0;
	};
}