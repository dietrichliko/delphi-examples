# Moden DELPHI Example01
#
# List tracks and vertices in Fortran

cmake_minimum_required(VERSION 3.26)

project(DELPHI-example01 VERSION 0.1 LANGUAGES Fortran)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake")
find_package(Delphi REQUIRED)

configure_file(example01.cra.in example01.cra)
ypatchy(example01.f example01.cra)

add_executable(example01 ${CMAKE_CURRENT_BINARY_DIR}/example01.f)
target_link_dellib(example01 phdst)
target_link_cernlib(example01 packlib)
