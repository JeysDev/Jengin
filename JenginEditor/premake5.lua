project "JenginEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    links 
    {
        "Jengin"
    }
    
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}/")
	objdir ("%{wks.location}/bin/Ιnt/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }
    includedirs
    {
        "%{wks.location}/Jengin/3pLibs/spdlog/include",
        "%{wks.location}/Jengin/src"
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

        defines "JN_DEBUG"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

        defines "JN_RELEASE"

    filter "configurations:Dist"
        runtime "Release"
        optimize "on"
        symbols "off"

        defines "JN_DIST"