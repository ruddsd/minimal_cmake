#include <minimal_lib/minimal_lib.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/HelperMacros.h>

class qa_basic : public ::CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE( qa_basic );
        CPPUNIT_TEST( test_printing );
    CPPUNIT_TEST_SUITE_END();

public:
    void test_printing();


};

CPPUNIT_TEST_SUITE_REGISTRATION( qa_basic );

void
qa_basic::test_printing()
{
    print_something();

}

