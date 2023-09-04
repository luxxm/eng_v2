cmake_minimum_required(VERSION 3.1)

project(v2)

set(PROJECT_SOURCE_DIR "../src/")
#set(UTILS {PROJECT_SOURCE_DIR}/utils/vectors.hpp)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(v2eng ${SOURCES})
