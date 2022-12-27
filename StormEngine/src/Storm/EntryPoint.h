#pragma once
#include "Application.h"

#ifdef STM_BUILD_WINDOW

extern Storm::Application* Storm::CreateApplication;

int main(int argc, char** argv)
{
	auto app = Storm::CreateApplication();
	app->Run();
	delete app;
}

#endif
