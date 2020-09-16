cmake_minimum_required(VERSION 3.17)
project(Kseri VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB HEADER_FILES "*.h" "*.hpp")
file(GLOB SOURCE_FILES "*.cpp")

add_executable(kseri ${SOURCE_FILES})