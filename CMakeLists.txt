cmake_minimum_required(VERSION 3.20)
project(FileProcessing)

set(CMAKE_CXX_STANDARD 14)

add_executable(FileProcessor main.cpp FileProcessing.cpp Formatting.cpp)
