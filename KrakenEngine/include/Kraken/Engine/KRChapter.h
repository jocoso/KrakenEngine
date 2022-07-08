#pragma once
#include <Kraken/Core/KRBase.h>

namespace kraken {

	class KREntity;
	class KRChapter : public KRBase {
	public:
		KRChapter() {}
		virtual ~KRChapter() {}
		virtual void release() = 0;

		virtual KREntity* createEntity() = 0;
	};
}