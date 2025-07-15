#include "card.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Card* deck = create_deck();
    for (int i = 0; i < 52; i++) {
        char* card_string = card_to_string(deck[i]);

        if (i == 51) {
            printf("%s.\n", card_string);
        } else {
            printf("%s, ", card_string);
        }

        free(card_string);
    }

    free(deck);

    return 0;
}
