#pragma once

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "../models/deck.h"

MunitResult test_create_deck() {
    Card* deck = create_deck();

    Suit suits[4] = {HEARTS, DIAMONDS, SPADES, CLUBS};
    size_t deck_index = 0;

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 1; j < 14; j++) {
            Card expected_card = {j, false, suits[i]};
            
            assert_int(expected_card.value, ==, deck[deck_index].value);
            assert_int(expected_card.drawn, ==, deck[deck_index].drawn);
            assert_int(expected_card.suit, ==, deck[deck_index].suit);
            
            deck_index++;
        }
    }

    free(deck);
    return MUNIT_OK;
}