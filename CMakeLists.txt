cmake_minimum_required(VERSION 3.14)
project(hwr)

set(CMAKE_CXX_STANDARD 14)
set(PLATFORM x86)

add_library(hwr SHARED library.cpp library.h hand_write_recognizer.h hand_write_recognizer.cpp)