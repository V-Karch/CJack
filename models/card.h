#pragma once

typedef enum {
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS
} Suit;

typedef struct {
    unsigned int value;
    Suit suit;
} Card;

const char* suit_to_string(Suit suit);
char* card_to_string(Card card);