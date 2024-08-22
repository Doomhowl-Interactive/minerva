#pragma once
#ifndef CORE
#define CORE
	#ifdef AT_CPP_API
		#ifdef AT_BUILD_DLL
		#define AT_API __declspec(dllexport)
		#else
		#define AT_API __declspec(dllimport)
		#endif // AT_BUILD_DLL
	#else
		#define AT_API
	#endif // AT_CPP_API
	#ifdef AT_C_API
		#define AT_EXTERN_START extern "C" {
		#define AT_EXTERN_END }
	#else
		#define AT_EXTERN_START
		#define AT_EXTERN_END
	#endif // AT_C_API

#if !defined(AT_C_API) && !defined(AT_CPP_API)
	#error an api type needs to be specified see python build.py -h (AT_C_API or AT_CPP_API)
#endif
#ifndef STRINGYFY
#define STRINGIFY(x) #x
#endif // !STRINGYFY

#endif // !CORE

