cmake_minimum_required(VERSION 4.3.0)
project(ReverseKGroup)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Demo
add_executable(demo 
    demos/ejemplos.cpp 
    src/solution.cpp)

# Tests
add_executable(tests 
    tests/test.cpp 
    src/solution.cpp)

# Benchmark
add_executable(benchmark 
    benchmark/benchmark.cpp 
    src/solution.cpp)

enable_testing()
add_test(NAME pruebas COMMAND test)
