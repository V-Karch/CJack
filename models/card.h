#pragma once

#ifndef COLOR_RESET 
    #define COLOR_RESET "\033[0m"
#endif

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
const char* suit_to_color(Suit suit);
char* card_to_string(Card card);