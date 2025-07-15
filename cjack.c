#include "models/card.h"
#include "models/deck.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Card* deck = create_deck();
    printf("Unshuffled Deck:\n");
    display_deck(deck);

    printf("\n");
    shuffle_deck(deck);
    printf("Shuffed Deck:\n");
    display_deck(deck);

    free(deck);

    return 0;
}
