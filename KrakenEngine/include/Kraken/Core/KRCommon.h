#pragma once
#include <stdlib.h>

#define KR_WINDOWS (_WIN32 || _WIN64)

#if KR_WINDOWS

	#if defined KRAKEN_EXPORTS
		#define KR_API __declspec(dllexport)
	#else
		#define KR_API __declspec(dllimport)
	#endif

	#define ASSERT(x) if ((x)==0) {abort();}

#endif

namespace kraken {
	class KRWindow;
	class KRChapter;
	typedef unsigned int ui32;
}