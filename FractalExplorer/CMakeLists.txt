﻿# CMakeList.txt : CMake project for FractalExplorer, include source and define
# project specific logic here.
#

# Find packages that are required for the project to execute properly
find_package(SDL2 REQUIRED)

# Add source to this project's executable.
add_executable (FractalExplorer
 "main.cpp"
 "Window/Window.cpp" "Window/Window.h"
 "Fractal/Fractal.cpp" "Fractal/Fractal.h"
 "Vector2/Vector2.cpp" "Vector2/Vector2.h"
)

# Link libraries so they are visible for the project
target_link_libraries(FractalExplorer SDL2::SDL2 SDL2::SDL2main)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FractalExplorer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
