cmake_minimum_required(VERSION 3.26)

project(DELPHI-examples VERSION 0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(Delphi REQUIRED)

add_library(DelphiAnalysis STATIC src/PhdstAnalysis.cxx src/SkelanaAnalysis.cxx)

target_include_directories(DelphiAnalysis PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(example01)
add_subdirectory(example02)
add_subdirectory(example03)
add_subdirectory(example04)
add_subdirectory(example05)
add_subdirectory(example06)
