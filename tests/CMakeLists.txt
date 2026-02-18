include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(    TEST_SOURCES
        tests_vector.cpp
        tests_line.cpp
        tests_segment.cpp
        tests_line_solver.cpp
        tests_segment_solver.cpp
        tests_line.cpp
        tests_line_solver.cpp
        tests_segment_solver.cpp
        tests_segment.cpp
)

add_executable(SegmentTests ${TEST_SOURCES})

target_link_libraries(SegmentTests
        PRIVATE
        SegmentLib
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(SegmentTests)