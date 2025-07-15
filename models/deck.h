#pragma once

#include "card.h"

Card* create_deck(void);
void shuffle_deck(Card* deck);
void display_deck(Card* deck);
void set_card_drawn(Card* deck, int index);