# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. The RELATIVE flag makes it easier to extract an executable's name
# automatically.

file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".c" "" testname ${testsourcefile} ) # File type. Example: `.c`
    add_executable( ${testname} ${testsourcefile} )

    if(OpenMP_C_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_C)
    endif()
    if(MATH_LIBRARY)
        target_link_libraries(${testname} ${MATH_LIBRARY})
    endif()
    install(TARGETS ${testname} DESTINATION "bin/dynamic_programming") # Folder name. Do NOT include `<>`

endforeach( testsourcefile ${APP_SOURCES} )
