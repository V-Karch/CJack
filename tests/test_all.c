#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "test_card.h"

#ifndef MAKE_TEST
    #define MAKE_TEST(name, func) { name, func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
#endif

#ifndef TEST_TERMINATOR
    #define TEST_TERMINATOR { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
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
    MAKE_TEST("/card/create_undrawn_ace_hearts", test_create_undrawn_ace_hearts),
    MAKE_TEST("/card/suit_to_color_hearts", test_suit_to_color_hearts),
    MAKE_TEST("/card/suit_to_color_diamonds", test_suit_to_color_diamonds),
    MAKE_TEST("/card/suit_to_color_spades", test_suit_to_color_spades),
    MAKE_TEST("/card/suit_to_color_clubs", test_suit_to_color_clubs),
    
    TEST_TERMINATOR
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
