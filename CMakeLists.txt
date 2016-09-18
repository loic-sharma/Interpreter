cmake_minimum_required (VERSION 3.1)

project (Anvil)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

enable_testing()

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)
