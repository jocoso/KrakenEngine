#pragma once
#include <Kraken/Core/KRBase.h>

namespace kraken {

	class KRChapter {
	public:
		KRChapter() {}
		~KRChapter() {}
		virtual void release() = 0;
	};
}