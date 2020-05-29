if(USE_OPENMP)
    find_package(OpenMP)
endif()

# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file( GLOB_RECURSE APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
# file( GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/*.c )
# AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    string( REPLACE ".c" "" testname ${testsourcefile} )
    string( REPLACE "/" "-" testname ${testname} )
    string( REPLACE "\\" "-" testname ${testname} )
    string( REPLACE " " "_" testname ${testname} )
    add_executable( ${testname} ${testsourcefile} )
    
    if(OpenMP_C_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_C)
    endif()
    set_target_properties(${testname} PROPERTIES LINKER_LANGUAGE C)
    install(TARGETS ${testname} DESTINATION "bin/misc")

endforeach( testsourcefile ${APP_SOURCES} )
