#include "Log.h"
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

namespace Storm
{
	void Log::Init()
	{
		if (Storm::Log::initialized) return;
		
		logger = GetStdHandle(STD_OUTPUT_HANDLE);

		LogInfo(Storm::Core, "Initialized Storm Log!");

		Storm::Log::initialized = true;
	}

	void Log::LogError(Loggers log, const char* message)
	{
		if (log == Storm::Core)
		{
			SetConsoleTextAttribute(logger, FOREGROUND_RED);
			cout << "STORM: " << message << endl;
		}
		else if (log == Storm::Client)
		{
			SetConsoleTextAttribute(logger, FOREGROUND_RED);
			cout << "CLIENT: " << message << endl;
		}
	}

	void Log::LogDebug(Loggers log, const char* message)
	{
		if (log == Storm::Core)
		{
			SetConsoleTextAttribute(logger, FOREGROUND_GREEN);
			cout << "STORM: " << message << endl;
		}
		else if (log == Storm::Client)
		{
			SetConsoleTextAttribute(logger, FOREGROUND_GREEN);
			cout << "CLIENT: " << message << endl;
		}
	}

	void Log::LogInfo(Loggers log, const char* message)
	{
		if (log == Storm::Core)
		{
			SetConsoleTextAttribute(logger, FOREGROUND_BLUE);
			cout << "STORM: " << message << endl;
		}
		else if (log == Storm::Client)
		{
			SetConsoleTextAttribute(logger, FOREGROUND_BLUE);
			cout << "CLIENT: " << message << endl;
		}
	}
}