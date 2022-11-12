project "BVHLib"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs { "src" }

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"BVHLIB_PLATFORM_WINDOWS"
		}

	filter "system:macosx"
		pic "On"
		systemversion "11.2"
		defines
		{
			"BVHLIB_PLATFORM_WINDOWS"
		}