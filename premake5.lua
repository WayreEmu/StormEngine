workspace "StormEngine"
	architecture "x64"
	startproject "StormPlayer"
	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "StormEngine"
	location "StormEngine"
	kind "SharedLib"
	language  "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"STM_BUILD_WINDOW",
			"STM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..  outputdir .. "/StormPlayer")
		}

	filter "configurations:Debug"
		defines "STM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "STM_RELEASE"
		symbols "On"

project "StormPlayer"
	location "StormPlayer"
	kind "ConsoleApp"
	language  "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"StormEngine/src"
		-- "%{prj.name}/vendor/glfw3/include"
	}

	links
	{
		"StormEngine"
	}

	libdirs
	{
		"bin/" .. outputdir .. "StormEngine/"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"STM_BUILD_WINDOW",
		}

	filter "configurations:Debug"
		defines "STM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "STM_RELEASE"
		symbols "On"