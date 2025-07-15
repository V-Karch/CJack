#pragma once

#include "card.h"

Card* create_deck(void); // Requires free()
void shuffle_deck(Card* deck);
void display_deck(Card* deck);
void set_card_drawn(Card* deck, size_t index);
void set_all_cards_undrawn(Card* deck);
int find_next_undrawn_card(Card* deck);