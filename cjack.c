#include "card.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Card* deck = create_deck();
    for (int i = 0; i < 52; i++) {
        if (i == 51) {
            printf("%s.\n", card_to_string(deck[i]));
        } else {
            printf("%s, ", card_to_string(deck[i]));
        }

    }

    free(deck);

    return 0;
}
