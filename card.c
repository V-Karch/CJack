#include "card.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

const char* suit_to_string(Suit suit) {
    switch (suit) {
        case HEARTS:
            return "hearts";
        case DIAMONDS:
            return "diamonds";
        case SPADES:
            return "spades";
        case CLUBS:
            return "clubs";
        default:
            return "unknown";
    };
};

char* card_to_string(Card card) {
    char* result = NULL;
    const char* suit = suit_to_string(card.suit);

    if (card.value == 1) {         // ACE
        asprintf(&result, "Card{ace, %s}", suit);
    } else if (card.value <= 10) { // NUMERIC
        asprintf(&result, "Card{%d, %s}", card.value, suit);
    } else if (card.value == 11) { // JACK
        asprintf(&result, "Card{jack, %s}", suit);
    } else if (card.value == 12) { // QUEEN
        asprintf(&result, "Card{queen, %s}", suit);
    } else if (card.value == 13) { // KING
        asprintf(&result, "Card{king, %s}", suit);
    } else {
        asprintf(&result, "Card{unknown, %s}", suit);
    }

    return result;
} // Remember to free the returned string here
