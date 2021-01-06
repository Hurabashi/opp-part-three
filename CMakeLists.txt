cmake_minimum_required(VERSION 3.17)
project(2_0V)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_0V main.cpp Header.h Zmogus.cpp Zmogus.h Studentas.cpp Studentas.h StudentManager.cpp StudentManager.h)
add_subdirectory(Google_tests)