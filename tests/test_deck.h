#pragma once

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "../models/deck.h"

static MunitResult test_create_deck() {
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

static MunitResult test_set_card_drawn_0() {
    Card* deck = create_deck();

    size_t expected_value = 1;
    bool expected_drawn = true;
    Suit expected_suit = HEARTS;

    set_card_drawn(deck, 0);

    assert_int(expected_value, ==, deck[0].value);
    assert_int(expected_drawn, ==, deck[0].drawn);
    assert_int(expected_suit, ==, deck[0].suit);

    free(deck);
    return MUNIT_OK;
}

static MunitResult test_set_all_cards_drawn() {
    Card* deck = create_deck();

    bool expected_drawn = true;

    for (size_t i = 0; i < 52; i++) {
        set_card_drawn(deck, i);
        assert_int(expected_drawn, ==, deck[i].drawn);
    }

    free(deck);
    return MUNIT_OK;
}

static MunitResult test_set_all_cards_undrawn() {
    Card* deck = create_deck();

    bool expected_drawn = false;

    for (size_t i = 0; i < 52; i++) {
        set_card_drawn(deck, i);
        // Setting everything to drawn
    }

    set_all_cards_undrawn(deck);
    // Setting everything back to undrawn
    for (size_t i = 0; i < 52; i++) {
        assert_int(expected_drawn, ==, deck[i].drawn);
    }

    free(deck);
    return MUNIT_OK;
}

static MunitResult test_find_next_undrawn_card_invalid() {
    Card* deck = create_deck();

    int expected_value = -1;

    for (size_t i = 0; i < 52; i++) {
        set_card_drawn(deck, i);
        // Setting everything to drawn
    }

    int actual_value = find_next_undrawn_card(deck);

    assert_int(expected_value, ==, actual_value);

    free(deck);
    return MUNIT_OK;
}

static MunitResult test_find_next_undrawn_card_4() {
    Card* deck = create_deck();

    int expected_value = 4;

    for (size_t i = 0; i < 4; i++) {
        set_card_drawn(deck, i);
        // Setting indices 0-3 to drawn
    }

    int actual_value = find_next_undrawn_card(deck);

    assert_int(expected_value, ==, actual_value);

    free(deck);
    return MUNIT_OK;
}