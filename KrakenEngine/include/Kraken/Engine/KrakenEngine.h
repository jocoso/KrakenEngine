#pragma once

#include <Kraken/Core/KRCommon.h>
#include <Kraken/Core/KRBase.h>

namespace kraken {

	class KrakenEngine : public KRBase {

	public:
		KrakenEngine() {}
		virtual ~KrakenEngine() {}
		virtual void release() = 0;
		
		virtual KRChapter* createChapter() = 0;
		virtual ui32 getNumChapters() = 0;
	};

	KR_API KrakenEngine* CreateKrakenEngine();

}