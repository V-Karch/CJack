#pragma once

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "../models/card.h"

static MunitResult test_create_undrawn_ace_hearts() {
    Card card = {1, false, HEARTS};

    int expected_value = 1;
    bool expected_drawn = false;
    Suit expected_suit = HEARTS;

    assert_int(expected_value, ==, card.value);
    assert_int(expected_drawn, ==, card.drawn);
    assert_int(expected_suit, ==, card.suit);

    return MUNIT_OK;
}

static MunitResult test_suit_to_color_hearts() {
    Suit suit = HEARTS;

    const char* expected_string = "\033[38;2;255;116;116m";
    const char* actual_string = suit_to_color(suit);

    assert_string_equal(expected_string, actual_string);

    return MUNIT_OK;
}

static MunitResult test_suit_to_color_diamonds() {
    Suit suit = DIAMONDS;

    const char* expected_string = "\033[38;2;255;177;116m";
    const char* actual_string = suit_to_color(suit);

    assert_string_equal(expected_string, actual_string);

    return MUNIT_OK;
}

static MunitResult test_suit_to_color_spades() {
    Suit suit = SPADES;

    const char* expected_string = "\033[38;2;116;117;255m";
    const char* actual_string = suit_to_color(suit);

    assert_string_equal(expected_string, actual_string);

    return MUNIT_OK;
}

static MunitResult test_suit_to_color_clubs() {
    Suit suit = CLUBS;

    const char* expected_string = "\033[38;2;116;211;255m";
    const char* actual_string = suit_to_color(suit);

    assert_string_equal(expected_string, actual_string);

    return MUNIT_OK;
}

static MunitResult test_card_to_string_undrawn_ace_diamonds() {
    Card card = {1, false, DIAMONDS};

    const char* expected_string = "\033[38;2;255;177;116mCard{ace, not drawn, diamonds}\033[0m";
    char* actual_string = card_to_string(card);

    assert_string_equal(expected_string, actual_string);
    free(actual_string);

    return MUNIT_OK;
}

static MunitResult test_card_to_string_drawn_queen_spades() {
    Card card = {12, true, SPADES};

    const char* expected_string = "\033[38;2;116;117;255mCard{queen, drawn, spades}\033[0m";
    char* actual_string = card_to_string(card);

    assert_string_equal(expected_string, actual_string);
    free(actual_string);

    return MUNIT_OK;
}

static MunitResult test_card_to_string_drawn_invalid_clubs() {
    Card card = {30, true, CLUBS};

    const char* expected_string = "\033[38;2;116;211;255mCard{unknown, drawn, clubs}\033[0m";
    char* actual_string = card_to_string(card);

    assert_string_equal(expected_string, actual_string);
    free(actual_string);

    return MUNIT_OK;
}