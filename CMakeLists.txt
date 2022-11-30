cmake_minimum_required(VERSION 3.23)
project(Siaod2sem)

set(CMAKE_CXX_STANDARD 23)


#message(STATUS "start running cmake...")
#
#find_package(Boost 1.80.0 COMPONENTS system filesystem REQUIRED)
#
#if(Boost_FOUND)
#
#    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
#    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
#
#    include_directories(${Boost_INCLUDE_DIRS})
#
#endif()
#
#add_executable()
#
#
#if(Boost_FOUND)
#
#    target_link_libraries(BoostTest ${Boost_LIBRARIES})
#
#endif()

add_executable(Siaod2sem Task7/main.cpp Task7/LZ77.h Task7/LZ77.cpp Task7/LZ78.h Task7/LZ78.cpp Task7/ShennonFano.h Task7/ShennonFano.cpp Task7/az100000.h Task7/Huffman.h Task7/Huffman.cpp)
