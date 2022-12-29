#pragma once
#include <iostream>

#ifdef STM_BUILD_WINDOW

extern Storm::Application* Storm::CreateApplication();

int main(int argc, char** argv)
{
	Storm::Log::Init();
	//Storm::Log::LogInfo(Storm::Core, "Testing");

	auto app = Storm::CreateApplication();
	app->Run();
	delete app;
}

#endif
