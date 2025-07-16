#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "test_card.h"
#include "test_deck.h"
#include "test_hand.h"

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
    // Sample Test
    MAKE_TEST("/test_sample", test_sample),
    // Card Tests
    MAKE_TEST("/card/create_undrawn_ace_hearts", test_create_undrawn_ace_hearts),
    MAKE_TEST("/card/suit_to_color_hearts", test_suit_to_color_hearts),
    MAKE_TEST("/card/suit_to_color_diamonds", test_suit_to_color_diamonds),
    MAKE_TEST("/card/suit_to_color_spades", test_suit_to_color_spades),
    MAKE_TEST("/card/suit_to_color_clubs", test_suit_to_color_clubs),
    MAKE_TEST("/card/card_to_string_undrawn_ace_diamonds", test_card_to_string_undrawn_ace_diamonds),
    MAKE_TEST("/card/card_to_string_drawn_queen_spades", test_card_to_string_drawn_queen_spades),
    MAKE_TEST("/card/card_to_string_drawn_invalid_clubs", test_card_to_string_drawn_invalid_clubs),
    // Deck Tests
    MAKE_TEST("/deck/create_deck", test_create_deck),
    MAKE_TEST("/deck/set_card_drawn_0", test_set_card_drawn_0),
    MAKE_TEST("/deck/set_all_cards_drawn", test_set_all_cards_drawn),
    MAKE_TEST("/deck/set_all_cards_undrawn", test_set_all_cards_undrawn),
    MAKE_TEST("/deck/find_next_undrawn_card_invalid", test_find_next_undrawn_card_invalid),
    MAKE_TEST("/deck/find_next_undrawn_card_4", test_find_next_undrawn_card_4),
    // Hand Tests
    MAKE_TEST("/hand/draw_player_hand", test_draw_player_hand),
    MAKE_TEST("/hand/draw_dealer_hand", test_draw_dealer_hand),
    MAKE_TEST("/hand/calculate_hand_value_ace_3", test_calculate_hand_value_3_ace),
    // Termination character
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
