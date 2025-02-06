# Modern Delphi
#
# CMAKE Utility functions

cmake_minimum_required(VERSION 3.26)

project(
    Delphi 
    VERSION 0.1 
    LANGUAGES Fortran
    )

include_directories(${CMAKE_SOURCE_DIR/../include})
add_link_options("-lgfortran")

function(ypatchy FOUT CRA)

    add_custom_command(
        OUTPUT ${FOUT}
        MAIN_DEPENDENCY ${CRA}
        DEPENDS ${ARGN}
        COMMAND nypatchy - ${FOUT} ${CRA} nypatchy.ylog .go
        COMMENT "Running nypatchy on ${CRA}"
        VERBATIM
        )

endfunction()

function(target_link_cernlib TARGET)

    execute_process(
        COMMAND cernlib ${ARGN}
        OUTPUT_VARIABLE CERNLIBS
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
    target_link_libraries(${TARGET} PRIVATE ${CERNLIBS})

endfunction()

function(target_link_dellib TARGET)

    execute_process(
        COMMAND dellib ${ARGN}
        OUTPUT_VARIABLE DELLIBS
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
    target_link_libraries(${TARGET} PRIVATE ${DELLIBS})

endfunction()