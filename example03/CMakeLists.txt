# Moden DELPHI Example01
#
# List tracks and vertices in Fortran

cmake_minimum_required(VERSION 3.26)

project(Example03 VERSION 0.1 LANGUAGES Fortran)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake")
find_package(Delphi REQUIRED)

configure_file(example03.cra.in example03.cra)
ypatchy(example03.f example03.cra ${PROJECT_SOURCE_DIR}/example03.car)

add_executable(example03 ${CMAKE_CURRENT_BINARY_DIR}/example03.f)
target_link_dellib(example03 skelana dstana pxdst vfclap vdclap ux tanagra ufield bsaurus herlib trigger uhlib dstana)
target_link_cernlib(example03 genlib packlib kernlib ariadne herwig jetset74)
target_compile_options(example03 PRIVATE -Wno-tabs)
