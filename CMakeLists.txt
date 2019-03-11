cmake_minimum_required(VERSION 3.13)
project(CarDetection)

set(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(CarDetection main.cpp)
target_link_libraries(CarDetection ${OpenCV_LIBS})