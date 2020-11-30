set(MINIMAL_LIB_HEADERS
  ${CMAKE_SOURCE_DIR}/include/minimal_lib/minimal_lib.h
  )

set(MINIMAL_LIB_SOURCES
    minimal_lib.cpp
  )

set(MINIMAL_LIB_DEPS ${MINIMAL_LIB_HEADERS} ${MINIMAL_LIB_SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(minimal_lib SHARED ${MINIMAL_LIB_DEPS})

install(
  TARGETS minimal_lib
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}
  EXPORT minimal_lib-targets)

install(
  EXPORT minimal_lib-targets
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig)
  
