#pragma once
#include <Kraken/Core/KRBase.h>

namespace kraken {
	class KREntity;
	class KRScene: public KRBase {
	public:
		KRScene() {}
		virtual ~KRScene() {}
		virtual void release() = 0;

		virtual KREntity* createEntity() = 0;
	};
}