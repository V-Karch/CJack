#pragma once

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "../models/card.h"

MunitResult test_create_undrawn_ace_hearts() {
    Card card = {1, false, HEARTS};

    int expected_value = 1;
    bool expected_drawn = false;
    Suit expected_suit = HEARTS;

    assert_int(expected_value, ==, card.value);
    assert_int(expected_drawn, ==, card.drawn);
    assert_int(expected_suit, ==, card.suit);

    return MUNIT_OK;
}

