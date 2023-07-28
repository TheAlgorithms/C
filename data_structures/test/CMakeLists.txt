file(
  GLOB APP_TESTS
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.c)
foreach(testsourcefile ${APP_TESTS})
  string(REPLACE ".c" "" testname ${testsourcefile}) # File type. Example: `.c`
  message(STATUS "Adding test ${testname}")
  add_executable(${testname} ${testsourcefile})

  target_link_libraries(${testname} data_structures)

  if(OpenMP_C_FOUND)
    target_link_libraries(${testname} OpenMP::OpenMP_C)
  endif()
  if(MATH_LIBRARY)
    target_link_libraries(${testname} ${MATH_LIBRARY})
  endif()
  install(TARGETS ${testname} DESTINATION "bin/<foldername>") # Folder name. Do
                                                              # NOT include `<>`

endforeach(testsourcefile ${APP_TESTS})
