#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#ifndef MAKE_TEST
    #define MAKE_TEST(name, func) { name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
#endif

// Simple test that asserts 1 == 1
// Just to make sure that munit testing works at all
MunitResult test_sample() {
    assert_int(1, ==, 1);
    return MUNIT_OK;
}

// Test array
MunitTest test_all_tests[] = {
    MAKE_TEST("/test_sample", test_sample),
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Test All Tests
MunitSuite test_all_suite = {
    "/all", // Overall name
    test_all_tests, // Suite to run
    NULL, 
    1, // Amount of times to run
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&test_all_suite, NULL, argc, argv);
}
