#pragma once

#define MUNIT_ENABLE_ASSERT_ALIASES
#include "../munit/munit.h"

#include "../models/hand.h"

static MunitResult test_draw_player_hand() {
    Card* deck = create_deck();
    Hand* player_hand = draw_player_hand(deck);

    Card expected_first_card = {1, true, HEARTS};
    Card expected_second_card = {2, true, HEARTS};
    size_t expected_length = 2;

    assert_int(expected_length, ==, player_hand->length);

    assert_int(expected_first_card.value, ==, player_hand->hand[0].value);
    assert_int(expected_first_card.drawn, == , player_hand->hand[0].drawn);
    assert_int(expected_first_card.suit, ==, player_hand->hand[0].suit);

    assert_int(expected_second_card.value, ==, player_hand->hand[1].value);
    assert_int(expected_second_card.drawn, == , player_hand->hand[1].drawn);
    assert_int(expected_second_card.suit, ==, player_hand->hand[1].suit);

    free_hand(player_hand);
    free(deck);
    return MUNIT_OK;
}

static MunitResult test_draw_dealer_hand() {
    Card* deck = create_deck();
    Hand* dealer_hand = draw_dealer_hand(deck);

    Card expected_first_card = {3, true, HEARTS};
    Card expected_second_card = {4, true, HEARTS};
    size_t expected_length = 2;

    assert_int(expected_length, ==, dealer_hand->length);

    assert_int(expected_first_card.value, ==, dealer_hand->hand[0].value);
    assert_int(expected_first_card.drawn, == , dealer_hand->hand[0].drawn);
    assert_int(expected_first_card.suit, ==, dealer_hand->hand[0].suit);

    assert_int(expected_second_card.value, ==, dealer_hand->hand[1].value);
    assert_int(expected_second_card.drawn, == , dealer_hand->hand[1].drawn);
    assert_int(expected_second_card.suit, ==, dealer_hand->hand[1].suit);

    free_hand(dealer_hand);
    free(deck);
    return MUNIT_OK;
}

static MunitResult test_calculate_hand_value_3_ace() {
    Card cards[] = {
        {1, true, HEARTS},
        {1, true, CLUBS},
        {1, true, DIAMONDS}
    };

    Hand hand[] = {3, cards};

    size_t expected_value = 13;
    assert_int(expected_value, ==, calculate_hand_value(hand));

    return MUNIT_OK;
}