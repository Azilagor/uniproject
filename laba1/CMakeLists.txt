cmake_minimum_required(VERSION 3.10)

project(MatrixOperations)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MatrixOperations main.cpp matrixOperations.cpp)
