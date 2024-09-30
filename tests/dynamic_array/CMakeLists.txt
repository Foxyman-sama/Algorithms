cmake_minimum_required(VERSION 3.30)
project(dynamic_array_tests)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 26)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} dynamic_array.cc)
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(${PROJECT_NAME} PUBLIC
    GTest::gtest_main
    GTest::gmock_main
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})