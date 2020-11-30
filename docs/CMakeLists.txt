find_package(Doxygen)

if (DOXYGEN_FOUND AND MINIMAL_LIB_GENERATE_DOCS)
  
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    @ONLY)

  set(DOC_DIR ${CMAKE_CURRENT_BINARY_DIR}/html)

  add_custom_command(
    OUTPUT ${DOC_DIR}
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating Minimal lib doxygen documentation")

  add_custom_target(minimal_lib_doxygen_target ALL DEPENDS ${DOC_DIR})

  install(
      DIRECTORY 
      ${DOC_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/doc/minimal_lib
      )


endif (DOXYGEN_FOUND AND MINIMAL_LIB_GENERATE_DOCS)  
