#pragma once
#include <stdlib.h>


#define KRAKEN_WINDOWS (_WIN32 || _WIN64)

#ifdef KRAKEN_WINDOWS

	#if defined KRAKEN_EXPORTS 
		#define KRAKEN_API __declspec(dllexport)
	#else
		#define KRAKEN_API __declspec(dllimport)
	#endif

#define KRASSERT(x) {\
	if((x) == 0) { __debugbreak(); abort(); }\
}

#endif