cmake_minimum_required(VERSION 3.0.0)
project(cppCoding VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cppCoding main.cpp 
                    ${PROJECT_SOURCE_DIR}/pair/pairtest.cpp
                    ${PROJECT_SOURCE_DIR}/tuple/tupletest.cpp
                    ${PROJECT_SOURCE_DIR}/exception/exceptiontest.cpp
                    ${PROJECT_SOURCE_DIR}/smartPointer/smartPointerTest.cpp
                    ${PROJECT_SOURCE_DIR}/numericlimits/numberiClimitsTest.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
