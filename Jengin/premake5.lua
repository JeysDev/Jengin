project "Jengin"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    pchheader "jnpch.h"
    pchsource "src/jnpch.cpp"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}/")
	objdir ("%{wks.location}/bin/Ιnt/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }
    
    includedirs
    {
        "%{wks.location}/Jengin/src",
        "%{wks.location}/Jengin/3pLibs/spdlog/include",
        "%{IncludeDir.GLFW}",
    }
    links
    {
        "GLFW",
        "opengl32.lib"
    }

    flags
    {
        "FatalWarnings"
    }

    filter "system:windows"
        systemversion "latest"
        defines "JN_PLATFORM_WINDOWS"        

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
        
        defines 
        {
            "JN_DEBUG",
            "JN_ENGINE_BUILD"
        }

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

        defines 
        {
            "JN_RELEASE",
            "JN_ENGINE_BUILD"
        }

    filter "configurations:Dist"
        runtime "Release"
        optimize "on"
        symbols "off"
        
        defines 
        {
            "JN_DIST",
            "JN_ENGINE_BUILD"
        }