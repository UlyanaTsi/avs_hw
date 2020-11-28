cmake_minimum_required(VERSION 3.17)
project(hw_4)

find_package(OpenMP REQUIRED)
set(CMAKE_CXX_STANDARD 14)


add_executable(hw_4 main.cpp)
target_link_libraries(hw_4 PRIVATE OpenMP::OpenMP_CXX)