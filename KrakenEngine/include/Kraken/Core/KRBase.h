#pragma once

namespace kraken {

	class KRBase {
	public:
		KRBase() {}
		virtual ~KRBase() {}
		virtual void release() = 0;
	};

}