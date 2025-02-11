# Moden DELPHI Example01
#
# List tracks and vertices in Fortran

cmake_minimum_required(VERSION 3.26)

project(DELPHI-example02 VERSION 0.1 LANGUAGES Fortran)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake")
find_package(Delphi REQUIRED)

configure_file(example02.cra.in example02.cra)
ypatchy(example02.f example02.cra ${CMAKE_CURRENT_SOURCE_DIR}/example02.car)

add_executable(example02 ${CMAKE_CURRENT_BINARY_DIR}/example02.f)
target_link_dellib(example02 skelana dstana pxdst vfclap vdclap ux tanagra ufield bsaurus herlib trigger uhlib dstana)
target_link_cernlib(example02 genlib packlib kernlib ariadne herwig jetset74)
target_compile_options(example02 PRIVATE -Wno-tabs)
