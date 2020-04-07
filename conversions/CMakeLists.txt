# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
# file( GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/*.c )
# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".c" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    # target_link_libraries( ${testname} function_timer )
    install(TARGETS ${testname} DESTINATION "bin/conversions")

endforeach( testsourcefile ${APP_SOURCES} )
