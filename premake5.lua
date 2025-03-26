workspace "CLoud"
    architecture "x64"
    startproject "CLoud"

    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["glfw"] = "CLoud/depend/glfw/include"
IncludeDir["glfw_deps"] = "CLoud/depend/glfw/deps"
IncludeDir["glad"] = "CLoud/depend/glad/include"

project "CLoud"
	location "CLoud"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
	}

    includedirs {
		"%{prj.name}/src",
		"%{prj.name}/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}"
	}

    links {
        "glfw",
        "glad"
    }

group "depend"
    project "glfw"
        location "CLoud/depend/glfw"
        kind "StaticLib"
        language "C"
        staticruntime "off"
        warnings "off"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            "%{prj.location}/include/glfw/glfw3.h",
            "%{prj.location}/include/glfw/glfw3native.h",
            "%{prj.location}/src/glfw_config.h",
            "%{prj.location}/src/context.c",
            "%{prj.location}/src/init.c",
            "%{prj.location}/src/input.c",
            "%{prj.location}/src/monitor.c",

            "%{prj.location}/src/null_init.c",
            "%{prj.location}/src/null_joystick.c",
            "%{prj.location}/src/null_monitor.c",
            "%{prj.location}/src/null_window.c",

            "%{prj.location}/src/platform.c",
            "%{prj.location}/src/vulkan.c",
            "%{prj.location}/src/window.c",
        }

        filter "system:linux"
            pic "On"

            systemversion "latest"
            
            files {
                "%{prj.location}/src/x11_init.c",
                "%{prj.location}/src/x11_monitor.c",
                "%{prj.location}/src/x11_window.c",
                "%{prj.location}/src/xkb_unicode.c",
                "%{prj.location}/src/posix_module.c",
                "%{prj.location}/src/posix_time.c",
                "%{prj.location}/src/posix_thread.c",
                "%{prj.location}/src/posix_module.c",
                "%{prj.location}/src/posix_poll.c",
                "%{prj.location}/src/glx_context.c",
                "%{prj.location}/src/egl_context.c",
                "%{prj.location}/src/osmesa_context.c",
                "%{prj.location}/src/linux_joystick.c"

            }

            defines {
                "_GLFW_X11"
            }

        filter "system:macosx"
            pic "On"

            files {
                "%{prj.location}/src/cocoa_init.m",
                "%{prj.location}/src/cocoa_monitor.m",
                "%{prj.location}/src/cocoa_window.m",
                "%{prj.location}/src/cocoa_joystick.m",
                "%{prj.location}/src/cocoa_time.c",
                "%{prj.location}/src/nsgl_context.m",
                "%{prj.location}/src/posix_thread.c",
                "%{prj.location}/src/posix_module.c",
                "%{prj.location}/src/osmesa_context.c",
                "%{prj.location}/src/egl_context.c"
            }

            defines {
                "_GLFW_COCOA"
            }

        filter "system:windows"
            systemversion "latest"

            files {
                "%{prj.location}/src/win32_init.c",
                "%{prj.location}/src/win32_joystick.c",
                "%{prj.location}/src/win32_module.c",
                "%{prj.location}/src/win32_monitor.c",
                "%{prj.location}/src/win32_time.c",
                "%{prj.location}/src/win32_thread.c",
                "%{prj.location}/src/win32_window.c",
                "%{prj.location}/src/wgl_context.c",
                "%{prj.location}/src/egl_context.c",
                "%{prj.location}/src/osmesa_context.c"
            }

            defines { 
                "_GLFW_WIN32",
                "_CRT_SECURE_NO_WARNINGS"
            }

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter { "system:windows", "configurations:Debug-AS" }	
            runtime "Debug"
            symbols "on"
            sanitize { "Address" }
            flags { "NoRuntimeChecks", "NoIncrementalLink" }

        filter "configurations:Release"
            runtime "Release"
            optimize "speed"

    project "glad"
        location "CLoud/depend/glad"
        kind "StaticLib"
        language "C"
        staticruntime "off"
        warnings "off"
    
        targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
        objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
        files {
            "%{prj.location}/include/glad/gl.h",
            "%{prj.location}/include/KHR/khrplatform.h",
            "%{prj.location}/src/gl.c"
        }
    
        includedirs {
            "%{prj.location}/include"
        }
    
        filter "system:windows"
            systemversion "latest"
    
        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"
    
        filter { "system:windows", "configurations:Debug-AS" }	
            runtime "Debug"
            symbols "on"
            sanitize { "Address" }
            flags { "NoRuntimeChecks", "NoIncrementalLink" }
    
        filter "configurations:Release"
            runtime "Release"
            optimize "speed"
            
group ""
