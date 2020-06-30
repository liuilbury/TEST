cmake_minimum_required(VERSION 3.16)
project(gdi_)

set(CMAKE_CXX_STANDARD 14)

add_executable(gdi_ main.cpp)
target_link_libraries(gdi_  PUBLIC gdiplus.lib)