file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )

foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".c" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} )
    
    if(OpenMP_C_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_C)
    endif()
    if(MATH_LIBRARY)
        target_link_libraries(${testname} ${MATH_LIBRARY})
    endif()
    install(TARGETS ${testname} DESTINATION "bin/process_scheduling_algorithms")

endforeach( testsourcefile ${APP_SOURCES} )