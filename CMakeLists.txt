cmake_minimum_required(VERSION 3.0.0)
project(cppCoding VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cppCoding main.cpp print.hpp 
                    ${PROJECT_SOURCE_DIR}/pair/pairtest.cpp
                    ${PROJECT_SOURCE_DIR}/tuple/tupletest.cpp
                    ${PROJECT_SOURCE_DIR}/exception/exceptiontest.cpp
                    ${PROJECT_SOURCE_DIR}/smartPointer/smartPointerTest.cpp
                    ${PROJECT_SOURCE_DIR}/numericlimits/numberiClimitsTest.cpp
                    ${PROJECT_SOURCE_DIR}/typetrait/typetraittest.cpp
                    ${PROJECT_SOURCE_DIR}/chrono/chronotest.cpp
                    ${PROJECT_SOURCE_DIR}/STL/container.cpp
                    ${PROJECT_SOURCE_DIR}/STL/algorithm.cpp
                    ${PROJECT_SOURCE_DIR}/STL/iterator.cpp
                    ${PROJECT_SOURCE_DIR}/STL/functionobj.cpp
                    ${PROJECT_SOURCE_DIR}/STL/array.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 11)
include(CPack)
