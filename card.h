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

Card* create_deck(void);
void shuffle_deck(Card* deck);
void display_deck(Card* deck);