include(CheckIncludeFile)

if(WIN32)
    CHECK_INCLUDE_FILE(winsock2.h WINSOCK_HEADER)
else()
    CHECK_INCLUDE_FILE(arpa/inet.h ARPA_HEADERS)
endif()

include(CheckSymbolExists)
if(ARPA_HEADERS OR WINSOCK_HEADER)
    # If necessary, use the RELATIVE flag, otherwise each source file may be listed
    # with full pathname. RELATIVE may makes it easier to extract an executable name
    # automatically.
    file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c )
    # file( GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/*.c )
    # AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} APP_SOURCES)
    foreach( testsourcefile ${APP_SOURCES} )
        # I used a simple string replace, to cut off .cpp.
        string(REPLACE ".c" "" testname ${testsourcefile})

        if(NOT WIN32)
            if(${testname} STREQUAL "fork" OR ${testname} STREQUAL "bool")
                continue()
            endif()
        endif()
        add_executable(${testname} ${testsourcefile})

        if (OpenMP_C_FOUND)
            target_link_libraries(${testname} PRIVATE OpenMP::OpenMP_C)
        endif ()
        if (MATH_LIBRARY)
            target_link_libraries(${testname} PRIVATE ${MATH_LIBRARY})
        endif ()
        # if(HAS_UNISTD)
        #     target_compile_definitions(${testname} PRIVATE HAS_UNISTD)
        # endif()
        # if(ARPA_HEADERS)
        #     target_compile_definitions(${testname} PRIVATE ARPA_HEADERS)
        # else()
        #     target_compile_definitions(${testname} PRIVATE WINSOCK_HEADER)
        # endif()

        if (WINSOCK_HEADER)
            target_link_libraries(${testname} PRIVATE ws2_32)   # link winsock library on windows
        endif()

        install(TARGETS ${testname} DESTINATION "bin/client_server")

    endforeach( testsourcefile ${APP_SOURCES} )
else()
    message(WARNING "socket headers not found in system.")
endif(ARPA_HEADERS OR WINSOCK_HEADER)
