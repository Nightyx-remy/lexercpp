cmake_minimum_required(VERSION 3.23)
project(lexercpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(lexercpp main.cpp tokens.cpp tokens.h lexer.cpp lexer.h)
