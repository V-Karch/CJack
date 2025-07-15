#include "testing_utils.h"
#include "../models/card.h"

#include <string.h>

bool test_card_create(void) {
    // Setup
    Card card = {1, false, HEARTS};

    // Expected
    size_t expected_value = 1;
    bool expected_drawn = false;
    Suit expected_suit = HEARTS;

    // Actual
    if (expected_value != card.value) { return false; }
    if (expected_drawn != card.drawn) { return false; }
    if (expected_suit != card.suit) { return false; }

    return true;
}

bool test_card_string_match_undrawn_ace_hearts(void) {
    // Setup
    Card card = {1, false, HEARTS};

    // Expected
    char* expected_string = "\033[38;2;255;116;116mCard{ace, not drawn, hearts}\033[0m";

    // Actual
    char* actual_string = card_to_string(card);

    bool result = strcmp(expected_string, actual_string) == 0;

    free(actual_string);
    return result;
}

bool test_card_string_match_drawn_queen_spades(void) {
    // Setup
    Card card = {12, true, SPADES};

    // Expected
    char* expected_string = "\033[38;2;116;117;255mCard{queen, drawn, spades}\033[0m";

    // Actual
    char* actual_string = card_to_string(card);

    bool result = strcmp(expected_string, actual_string) == 0;

    free(actual_string);
    return result;
}

bool test_suit_to_color_diamonds(void) {
    return strcmp("\033[38;2;255;177;116m", suit_to_color(DIAMONDS)) == 0;
}

bool test_suit_to_color_clubs(void) {
    return strcmp("\033[38;2;116;211;255m", suit_to_color(CLUBS)) == 0;
}

bool test_suit_to_color_spades(void) {
    return strcmp("\033[38;2;116;117;255m", suit_to_color(SPADES)) == 0;
}

bool test_suit_to_color_hearts(void) {
    return strcmp("\033[38;2;255;116;116m", suit_to_color(HEARTS)) == 0;
}

int main(void) {
    printf("Running tests for card functionality...\n");

    Test card_create = {"test_card_create()", *test_card_create};
    Test card_string_match_undrawn_ace_hearts = {"test_card_string_match_undrawn_ace_hearts()", *test_card_string_match_undrawn_ace_hearts};
    Test card_string_match_drawn_queen_spades = {"test_card_string_match_drawn_queen_spades()", *test_card_string_match_drawn_queen_spades};
    Test suit_to_color_diamonds = {"test_suit_to_color_diamonds()", *test_suit_to_color_diamonds};
    Test suit_to_color_hearts = {"test_suit_to_color_hearts()", *test_suit_to_color_hearts}; 
    Test suit_to_color_clubs = {"test_suit_to_color_clubs()", *test_suit_to_color_clubs};
    Test suit_to_color_spades = {"test_suit_to_color_spades()", *test_suit_to_color_spades};

    Test tests[] = {
        card_create, 
        card_string_match_undrawn_ace_hearts, 
        card_string_match_drawn_queen_spades, 
        suit_to_color_diamonds,
        suit_to_color_hearts,
        suit_to_color_clubs,
        suit_to_color_spades,
    };

    run_tests(tests, sizeof(tests) / sizeof(Test));
}
