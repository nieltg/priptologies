cmake_minimum_required(VERSION 3.1)
project(priptologies)

include_directories(include)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
