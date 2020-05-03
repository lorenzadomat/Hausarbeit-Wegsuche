cmake_minimum_required(VERSION 3.12)
project(UnitTest)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_executable(Wegsuche main.cpp)
add_executable(unit UnitTests.cpp)

target_link_libraries(unit ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()
add_test(NAME unit COMMAND unit)
