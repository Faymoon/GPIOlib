workspace "GPIOlib"
    configurations { "Release", "Debug" }
    location "build/"

    startproject "Project"

project "GPIOlib"

    kind "SharedLib"

    cppdialect "C++14"

    defines "GPIO_BUILD"

    includedirs "include/"

    files {
        "include/*.hpp",
        "include/*.inl",
        "src/*.cpp"
    }

    filter "configurations:Debug"
        targetdir "bin/Debug/"
		defines { "DEBUG" }
        symbols "On"
        buildoptions { "-g" }

	filter "configurations:Release"
        targetdir "bin/Release/"
		defines { "NDEBUG" }
        optimize "On"
    
    filter {}


