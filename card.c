#include "card.h"
#include <stdio.h>

char* suite_to_string(Suite suite) {
    switch (suite) {
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
    asprintf(&result, "Card{%d, %s}", card.value, suite_to_string(card.suite));
    return result;
}