#pragma once

#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

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
    size_t value;
    bool drawn;
    Suit suit;
} Card;


const char* suit_to_string(Suit suit);
const char* suit_to_color(Suit suit);
char* card_to_string(Card card); // Requires free()