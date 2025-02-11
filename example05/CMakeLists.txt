# Modern DELPHI Example03
#
# List tracks and vertices in C++

cmake_minimum_required(VERSION 3.26)

project(DELPHI-example05 VERSION 0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake")
find_package(Delphi REQUIRED)

add_executable(example05 example05.cxx Analysis05.cxx)
target_link_libraries(example05 PUBLIC DelphiAnalysis)
target_link_dellib(example05 skelana dstana pxdst vfclap vdclap ux tanagra ufield bsaurus herlib trigger uhlib dstana)
target_link_cernlib(example05 genlib packlib kernlib ariadne herwig jetset74)
target_include_directories(example05 PRIVATE ../include)
