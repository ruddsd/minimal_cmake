cmake_minimum_required(VERSION 2.8.12)

project(minimal_lib CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

enable_testing()

add_definitions(-Wall -W -std=c++11)

message("CMAKE_MODULE_PATH -> " ${CMAKE_MODULE_PATH})
message("CMAKE_CURRENT_BINARY_DIR -> " ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(docs)
add_subdirectory(include/minimal_lib)
add_subdirectory(lib)
add_subdirectory(qa)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/minimal_lib.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/minimal_lib.pc
  @ONLY)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Findminimal_lib.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/Findminimal_lib.cmake
  @ONLY)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/minimal_lib.pc
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig
  COMPONENT "minimal_lib")

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/Findminimal_lib.cmake
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/cmake/Modules
  COMPONENT "minimal_lib")
