#pragma once

#include <iostream>
#include <memory>
#include "Core.h"
#include <windows.h>

namespace Storm
{
	const char* CoreLoggerName = "STORM-CORE";
	const char* ClientLoggerName = "CLIENT";

	enum Loggers
	{
		Core = 'STMC',
		Client = 'CLT'
	};

	class STORM_API Log
	{
	public:
		static void Init();
		static void LogError(Loggers log, const char* message);
		static void LogDebug(Loggers log, const char* message);
		static void LogInfo(Loggers log, const char* message);
	private:
		static inline bool initialized;
		static inline HANDLE logger;
	};
}

