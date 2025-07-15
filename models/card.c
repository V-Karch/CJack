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
    const char* suit_color = suit_to_color(card.suit);

    if (card.value == 1) {         // ACE
        asprintf(&result, "%sCard{ace, %s}%s", suit_color, suit, COLOR_RESET);
    } else if (card.value <= 10) { // NUMERIC
        asprintf(&result, "%sCard{%d, %s}%s", suit_color, card.value, suit, COLOR_RESET);
    } else if (card.value == 11) { // JACK
        asprintf(&result, "%sCard{jack, %s}%s", suit_color, suit, COLOR_RESET);
    } else if (card.value == 12) { // QUEEN
        asprintf(&result, "%sCard{queen, %s}%s", suit_color, suit, COLOR_RESET);
    } else if (card.value == 13) { // KING
        asprintf(&result, "%sCard{king, %s}%s", suit_color, suit, COLOR_RESET);
    } else {
        asprintf(&result, "%sCard{unknown, %s}%s", suit_color, suit, COLOR_RESET);
    }

    return result;
} // Remember to free the returned string here

const char* suit_to_color(Suit suit) {
    switch (suit) {
        case HEARTS:
            return "\033[38;2;255;116;116m";
        case DIAMONDS:
            return "\033[38;2;255;177;116m";
        case SPADES:
            return "\033[38;2;116;117;255m";
        case CLUBS:
            return "\033[38;2;116;211;255m";
        default:
            return COLOR_RESET; // Reset if invalid
    };
}