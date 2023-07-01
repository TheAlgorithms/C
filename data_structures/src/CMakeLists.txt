file(
  GLOB APP_SOURCES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  **/*.c *.c)

# message(STATUS "APP_SOURCES: ${APP_SOURCES}")
get_property(APP_HEADERS GLOBAL PROPERTY APP_HEADERS)

add_library(data_structures ${APP_SOURCES} ${APP_HEADERS})
target_include_directories(data_structures
                           PUBLIC ${CMAKE_SOURCE_DIR}/data_structures/include)
