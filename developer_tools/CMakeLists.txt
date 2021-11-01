# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
# file( GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/*.c )
# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)

add_library(malloc_dbg malloc_dbg.c) # Create a static library from malloc_dbg.c file

foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".c" "" testname ${testsourcefile} )
    string( REPLACE ".C" "" testname ${testname} )
    string( REPLACE " " "_" testname ${testname} )

    if ("${testsourcefile}" STREQUAL "malloc_dbg.c")
        continue()
    endif()

    add_executable( ${testname} ${testsourcefile} )

    if ("${testname}" STREQUAL "test_malloc_dbg")
        target_link_libraries(${testname} malloc_dbg)
    endif()

    if(OpenMP_C_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_C)
    endif()
    
    if(MATH_LIBRARY)
        target_link_libraries(${testname} ${MATH_LIBRARY})
    endif()
    #    target_link_libraries(${testname} malloc_dbg) # Link the malloc_dbg library
    install(TARGETS ${testname} DESTINATION "bin/developer_tools")

endforeach( testsourcefile ${APP_SOURCES} )
