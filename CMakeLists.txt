cmake_minimum_required(VERSION 3.30)
project(animationProgramming)

set(CMAKE_CXX_STANDARD 17)

# use custom file to find libraries
if(WIN32)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
endif()

file (GLOB SOURCES
    main.cpp
    tools/*.cpp
    window/*.cpp
)

add_executable(animationProgramming ${SOURCES}
        tools/Logger.cpp
        tools/Logger.h
        window/Window.cpp
        window/Window.h)

find_package(glfw3 3.3 REQUIRED)
find_package(Vulkan REQUIRED)

# variable is set by FindGLFW3.cmake, reuse for Linux
if(UNIX)
    set(GLFW3_LIBRARY glfw)
endif()

include_directories(${GLFW3_INCLUDE_DIR} window tools)

if(MSVC)
    target_link_libraries(animationProgramming ${GLFW3_LIBRARY} Vulkan::Vulkan)
else()
    # Clang and GCC may need libstd++
    target_link_libraries(animationProgramming ${GLFW3_LIBRARY} Vulkan::Vulkan stdc++)
endif()