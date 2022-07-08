#pragma once
#include <Kraken/Core/KRBase.h>

namespace kraken {
	typedef size_t KREntityHandle;
	class KREntity : public KRBase {
	public:
		KREntity() {}
		virtual ~KREntity() {}

		virtual KREntityHandle getHandle() = 0;
	};
}