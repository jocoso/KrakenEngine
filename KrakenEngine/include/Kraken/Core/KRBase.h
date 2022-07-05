#pragma once

namespace kraken {
	class KRBase {
	public:
		KRBase() {}
		~KRBase(){}
		virtual void release() = 0;
	};
}