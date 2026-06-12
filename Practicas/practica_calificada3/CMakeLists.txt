cmake_minimum_required(VERSION 3.10)
project(ListRemovals)

set(CMAKE_CXX_STANDARD 17)

# Solución eficiente con Segment Tree
add_executable(demo_main
    src/solution.cpp
    demos/demo_main.cpp
)
target_include_directories(demo_main PRIVATE include)

# Solución ingenua
add_executable(demo_ingenuo
    src/solution.cpp
    demos/demo_ingenuo.cpp
)
target_include_directories(demo_ingenuo PRIVATE include)

# Demo
add_executable(demo
    src/solution.cpp
    demos/demo.cpp
)
target_include_directories(demo_ingenuo PRIVATE include)

# Tests Segment Tree
add_executable(test_segment_tree
    src/solution.cpp
    tests/test_segment_tree.cpp
)
target_include_directories(test_segment_tree PRIVATE include)

# Benchmark
add_executable(benchmark
    src/solution.cpp
    benchmark/benchmark.cpp
)
target_include_directories(benchmark PRIVATE include)