#pragma once


#ifdef STM_BUILD_WINDOW
	#ifdef STM_BUILD_DLL
		#define STORM_API __declspec(dllexport)
	#else
		#define STORM_API __declspec(dllimport)
	#endif
#endif