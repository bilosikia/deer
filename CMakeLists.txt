cmake_minimum_required(VERSION 3.5)
project(deer)

set(CMAKE_CXX_STANDARD 14)
aux_source_directory(src SOURCE_FILES)

add_executable(deer ${SOURCE_FILES})