file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
# file( GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/*.c )
# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)

foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".c" "" testname ${testsourcefile} )
    string( REPLACE ".C" "" testname ${testname} )
    string( REPLACE " " "_" testname ${testname} )

    add_executable( ${testname} ${testsourcefile} )

    if(OpenMP_C_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_C)
    endif()

    install(TARGETS ${testname} DESTINATION "bin/games/naval_battle")

endforeach( testsourcefile ${APP_SOURCES} )
