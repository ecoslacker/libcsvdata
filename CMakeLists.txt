cmake_minimum_required(VERSION 3.11)
project(CsvData)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(BUILD_SHARED_LIBS TRUE)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(csvdata SHARED src/csvdata.cpp)

