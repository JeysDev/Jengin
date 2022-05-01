include "Dependencies.lua"
workspace "Jengin"
    startproject "JenginEditor"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }
outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

group "Dependencies"
    include "Jengin/3pLibs/GLFW"
group ""

include "Jengin"
include "JenginEditor"
