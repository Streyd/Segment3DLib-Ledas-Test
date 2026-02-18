cmake_minimum_required(VERSION 3.31)
project(Ledas__Test)

set(CMAKE_CXX_STANDARD 26)

include_directories(include)

add_library(SegmentLib
        src/core/Vector3D.cpp
        src/core/Line3D.cpp
        src/core/Segment3D.cpp
        src/solvers/Line3DSolver.cpp
        src/solvers/Segment3DSolver.cpp
)

add_executable(Ledas__Test main.cpp)


target_link_libraries(Ledas__Test PRIVATE SegmentLib)

enable_testing()
add_subdirectory(tests)