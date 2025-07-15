#include "card.h"
#include <stdio.h>
#include <stdlib.h>

Card* create_deck(void) {
    Card* deck = malloc(52 * sizeof(Card));
    Suit suits[4] = {HEARTS, DIAMONDS, SPADES, CLUBS};
    
    unsigned int deck_index = 0;

    for (size_t i = 0; i < 4; i++) { // Suit
        for (size_t j = 1; j < 14; j++) { // Value
            deck[deck_index] = (Card){j, false, suits[i]};
            deck_index++;
        }
    }

    return deck;
} // Remember to free the deck memory later

void display_deck(Card* deck) {
    for (size_t i = 0; i < 52; i++) {
        char* card_string = card_to_string(deck[i]);

        if (i == 51) {
            printf("%s.\n", card_string);
        } else {
            printf("%s, ", card_string);
        }

        free(card_string);
    }
}

// Fisher-Yates shuffling implementation
// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void shuffle_deck(Card* deck) {
    for (size_t i = 51; i > 0; i--) {
        size_t j = rand() % (i + 1); // Random from 0-(i + 1) decreasing
        Card temp = deck[i]; // Store current index
        deck[i] = deck[j]; // Overwrite value at current index with random j
        deck[j] = temp; // Overwrite random j with current index
    } // Move on to the next lowest index
}

void set_card_drawn(Card* deck, int index) {
    deck[index].drawn = true; // Marks a card as invalid
}