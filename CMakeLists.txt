cmake_minimum_required(VERSION 3.22)
project(Algorithms_in_C
        LANGUAGES C
        VERSION 1.0.0
        DESCRIPTION "Set of algorithms implemented in C."
        )

# Set compilation standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)
if (MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    # add_compile_options(/Za)
endif (MSVC)

# check for math library
# addresses a bug when linking on OSX
find_library(MATH_LIBRARY m)

# Optional flag - can be set by user
# Default "ON"
option(USE_OPENMP "flag to use OpenMP for multithreading" ON)
if(USE_OPENMP)
    find_package(OpenMP)
    if (OpenMP_C_FOUND)
        message(STATUS "Building with OpenMP Multithreading.")
    else()
        message(STATUS "No OpenMP found, no multithreading.")
    endif()
endif()

## Check for some required header files
include(CheckIncludeFile)
include(CheckSymbolExists)
check_include_file(stdbool.h HAS_STDBOOL_H)
check_include_file(inttypes.h HAS_INTTYPES_H)
check_include_file(complex.h HAS_COMPLEX_H)
if(HAS_COMPLEX_H)
    check_symbol_exists(complex complex.h HAS_COMPLEX_TYPE)
endif(HAS_COMPLEX_H)
if (NOT HAS_STDBOOL_H)
    message(FATAL_ERROR "Missing required header: 'stdbool.h'")
endif()
if (NOT HAS_INTTYPES_H)
    message(FATAL_ERROR "Missing required header: 'inttypes.h'")
endif()

## Add subdirectories containing CMakeLists.txt
# to configure and compile files in the respective folders
add_subdirectory(developer_tools)
add_subdirectory(hash)
add_subdirectory(misc)
add_subdirectory(games)
add_subdirectory(audio)
add_subdirectory(sorting)
add_subdirectory(geometry)
add_subdirectory(graphics)
add_subdirectory(searching)
add_subdirectory(conversions)
add_subdirectory(client_server)
add_subdirectory(project_euler)
add_subdirectory(machine_learning)
add_subdirectory(process_scheduling_algorithms)
add_subdirectory(numerical_methods)
add_subdirectory(math)
add_subdirectory(cipher)
add_subdirectory(dynamic_programming)

## Configure Doxygen documentation system
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)
find_package(Doxygen OPTIONAL_COMPONENTS dot dia)
if(DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_USE_MATHJAX YES)
    set(DOXYGEN_GENERATE_HTML YES)
    # set(DOXYGEN_HTML_TIMESTAMP YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_INLINE_SOURCES YES)
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
    set(DOXYGEN_STRIP_CODE_COMMENTS NO)
    set(DOXYGEN_ENABLE_PREPROCESSING YES)
    set(DOXYGEN_EXT_LINKS_IN_WINDOW YES)
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
    set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
    set(DOXYGEN_FILE_PATTERNS *.c *.h *.md)
    set(DOXYGEN_MATHJAX_EXTENSIONS  TeX/AMSmath TeX/AMSsymbols)
    set(DOXYGEN_TAGFILES "doc/cppreference-doxygen-web.tag.xml=http://en.cppreference.com/w/")
    set(DOXYGEN_MATHJAX_RELPATH "https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML")
    if(Doxygen_dot_FOUND)
        set(DOXYGEN_HAVE_DOT YES)
        set(DOXYGEN_CALL_GRAPH YES)
        set(DOXYGEN_INTERACTIVE_SVG YES)
        set(DOXYGEN_DOT_IMAGE_FORMAT "svg")
    endif()
    if(OPENMP_FOUND)
        set(DOXYGEN_PREDEFINED "_OPENMP=1")
    endif()
    if(GLUT_FOUND)
        set(DOXYGEN_PREDEFINED ${DOXYGEN_PREDEFINED} "GLUT_FOUND=1")
    endif()

    doxygen_add_docs(
        doc
        ${PROJECT_SOURCE_DIR}
        COMMENT "Generate documentation"
    )
endif()

## Enable tool to generate binary distribution files
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
