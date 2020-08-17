# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
# file( GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/*.c )
# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".c" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} )
    
    if(OpenMP_C_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_C)
    endif()
    if(MATH_LIBRARY)
        target_link_libraries(${testname} ${MATH_LIBRARY})
    endif()
    install(TARGETS ${testname} DESTINATION "bin/geometry")

endforeach( testsourcefile ${APP_SOURCES} )
