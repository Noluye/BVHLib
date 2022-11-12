project "BVHLib-Sandbox"
	kind "ConsoleApp"
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

	includedirs
	{
		"../BVHLib/src"
	}

	links { "BVHLib" }

	filter "system:windows"
		systemversion "latest"

	filter "system:macosx"
		pic "On"
		systemversion "11.2"
