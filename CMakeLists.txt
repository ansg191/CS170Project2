cmake_minimum_required(VERSION 3.28)
project(CS170Project2)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/**.cpp" "src/**.h")

add_executable(CS170Project2 ${SOURCES})
