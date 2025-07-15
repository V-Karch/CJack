#pragma once

#include "card.h"
#include <stdio.h>
#include <stdlib.h>

Card* create_deck(void); // Requires free()
void shuffle_deck(Card* deck);
void display_deck(Card* deck);
void set_card_drawn(Card* deck, int index);