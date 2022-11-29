cmake_minimum_required(VERSION 3.23)
project(Siaod2sem)

set(CMAKE_CXX_STANDARD 23)
add_executable(Siaod2sem Task7/main.cpp Task7/LZ77.h Task7/LZ77.cpp Task7/LZ78.h Task7/LZ78.cpp Task7/ShennonFano.h Task7/ShennonFano.cpp)
