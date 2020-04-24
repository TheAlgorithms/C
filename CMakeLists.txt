cmake_minimum_required(VERSION 3.0)
project(Algorithms_in_C
    LANGUAGES C CXX
    VERSION 1.0.0
    DESCRIPTION "Set of algorithms implemented in C."
)

option(USE_OPENMP "flag to use OpenMP for multithreading" ON)

function(function_timer)
    set(CMAKE_BUILD_TYPE "Release")         # This is local to function
    add_subdirectory(function_timer EXCLUDE_FROM_ALL)
endfunction()

function_timer()

include_directories(function_timer/include)
# link_libraries(function_timer)
# include_directories(${CMAKE_BINARY_DIR}/include)
# link_directories(${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

add_subdirectory(conversions)
add_subdirectory(misc)
add_subdirectory(project_euler)
add_subdirectory(sorting)
add_subdirectory(searching)
add_subdirectory(numerical_methods)

if(USE_OPENMP)
    find_package(OpenMP)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
