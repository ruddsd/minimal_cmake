#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cstdlib>

int main(int argc, char* argv[])
{
    (void) argc;
    (void) argv;

    CppUnit::Test* suite = NULL;
    suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    CppUnit::TextTestRunner runner;
    runner.addTest(suite);
    runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), 
        std::cout));

    bool success = runner.run();
    return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}
