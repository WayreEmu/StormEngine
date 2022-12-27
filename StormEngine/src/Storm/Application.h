#pragma once

#ifdef Application_H
#endif

#include "Core.h"

namespace Storm
{
	class STORM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

