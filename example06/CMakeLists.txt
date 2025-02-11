# Modern DELPHI Example03
#
# List tracks and vertices in C++

cmake_minimum_required(VERSION 3.26)

project(DELPHI-example06 VERSION 0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake")
find_package(Delphi REQUIRED)
find_package(ROOT CONFIG REQUIRED)

add_executable(example06 example06.cxx Analysis06.cxx)
target_link_libraries(example06 PUBLIC DelphiAnalysis)
target_link_dellib(example06 skelana dstana pxdst vfclap vdclap ux tanagra ufield bsaurus herlib trigger uhlib dstana)
target_link_cernlib(example06 genlib packlib kernlib ariadne herwig jetset74)
target_include_directories(example06 PRIVATE ../include)

target_link_libraries(example06 PUBLIC ${ROOT_LIBRARIES})
target_include_directories(example06 SYSTEM PUBLIC ${ROOT_INCLUDE_DIRS})

