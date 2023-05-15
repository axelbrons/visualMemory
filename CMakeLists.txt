cmake_minimum_required(VERSION 3.23)
project(visualMemory C)

set(CMAKE_C_STANDARD 99)

add_executable(visualMemory src/main.c src/visualMemory.h src/visualMemory.c)

target_link_libraries(visualMemory -lmingw32 -lallegro-5.0.10-monolith-md-debug)