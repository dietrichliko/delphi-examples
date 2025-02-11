# Modern DELPHI Example03
#
# List tracks and vertices in C++

cmake_minimum_required(VERSION 3.26)

project(DELPHI-example04 VERSION 0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake")
find_package(Delphi REQUIRED)

add_executable(example04 example04.cxx)
target_link_libraries(example04 PUBLIC DelphiAnalysis)
target_link_dellib(example04 phdst)
target_link_cernlib(example04 packlib)
target_include_directories(example04 PRIVATE ../include)
