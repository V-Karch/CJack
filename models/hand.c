#include "hand.h"

#include <stdlib.h>

Card* draw_player_hand(Card* deck) {
    // Players cards will always be drawn first
    set_card_drawn(deck, 0);
    set_card_drawn(deck, 1);

    Card* hand = malloc(2 * sizeof(Card));
    hand[0] = deck[0];
    hand[1] = deck[1];

    return hand;
} // Remember to free the memory of these hands later

Card* draw_dealer_hand(Card* deck) {
    // Dealers cards will always be drawn second
    set_card_drawn(deck, 2);
    set_card_drawn(deck, 3);

    Card* hand = malloc(2 * sizeof(Card));

    hand[0] = deck[2];
    hand[1] = deck[3];

    return hand;
} // Remember to free the memory of these hands later