#pragma once

#include "deck.h"

Card* draw_player_hand(Card* deck); // Requires free()
Card* draw_dealer_hand(Card* deck); // Requires free()