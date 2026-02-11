cmake_minimum_required(VERSION 3.21)
project(WaveScope)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(WaveScope
    src/main.cpp
    src/AudioFileSampler.cpp
)

target_include_directories(WaveScope PRIVATE include)

target_link_libraries(WaveScope PRIVATE Qt6::Widgets)
