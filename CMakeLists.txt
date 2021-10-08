cmake_minimum_required(VERSION 3.1)

project(ModernC C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(heron src/heron.c)

enable_testing()

include_directories(include)


add_executable(test_heron tests/test_heron.c)
add_test("Heron" test_heron)

add_executable(test_derivative tests/test_derivative.c)
add_test("Derivative" test_derivative)

add_executable(test_quicksort tests/test_quicksort.c)
add_test("Quicksort" test_quicksort)

add_executable(test_mergesort tests/test_mergesort.c)
add_test("Mergesort" test_mergesort)

add_executable(test_pi tests/test_pi.c)
add_test("Pi" test_pi)