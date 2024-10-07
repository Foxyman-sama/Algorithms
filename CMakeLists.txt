cmake_minimum_required(VERSION 3.30)
project(Algorithms)

add_executable(${PROJECT_NAME} main.c)

enable_testing()

add_subdirectory(tests)
add_subdirectory(ds)
add_subdirectory(algorithms)