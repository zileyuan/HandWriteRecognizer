cmake_minimum_required(VERSION 3.14)
project(hwr)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-m32")
set(CMAKE_CXX_FLAGS "-m32")

add_library(hwr SHARED library.cpp library.h hand_write_recognizer.h hand_write_recognizer.cpp base64.h)