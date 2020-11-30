macro (minimal_lib_build_unit_tests LINK_DEPS QA_TESTS)

    message(STATUS "FIXME: find cppunit instead of assuming existance")
    foreach(QA_TEST ${${QA_TESTS}})
        # generate the test name
        set(TEST_NAME test-${QA_TEST})
        string(REPLACE "_" "-" TEST_NAME ${TEST_NAME})
        # generate the original qa source file name
        set(FILE_NAME qa_${QA_TEST}.cpp)
        string(REPLACE "-" "_" FILE_NAME ${FILE_NAME})
        # add the qa test
        minimal_lib_unit_test(${QA_TEST} ${TEST_NAME} ${FILE_NAME} ${${LINK_DEPS}})
    endforeach(QA_TEST)

endmacro (minimal_lib_build_unit_tests)
   
macro (minimal_lib_unit_test COMPONENT TEST_NAME SRCFILE LINK_DEPS)

    message(STATUS "  Adding component unit test: " ${COMPONENT})
    add_executable(${TEST_NAME} ${SRCFILE} qa_test.cpp)
    target_link_libraries(${TEST_NAME} ${ARGN} ${LINK_DEPS})
    add_test(${COMPONENT} ${TEST_NAME})

endmacro(minimal_lib_unit_test)

include_directories(${CMAKE_SOURCE_DIR}/include)

list(APPEND MINIMAL_LIB_QA_TESTS
    basic
  )

set(MINIMAL_LIB_QA_DEPS minimal_lib cppunit)

minimal_lib_build_unit_tests(MINIMAL_LIB_QA_DEPS MINIMAL_LIB_QA_TESTS)

