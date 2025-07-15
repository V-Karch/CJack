#pragma once

#include "deck.h"

typedef struct {
    size_t length;
    Card* hand;
} Hand;

Hand* draw_player_hand(Card* deck); // Requires free()
Hand* draw_dealer_hand(Card* deck); // Requires free()

void display_hand(Hand* hand);
void free_hand(Hand* hand);
void draw_next_card_to_hand(Hand* hand, Card* deck);