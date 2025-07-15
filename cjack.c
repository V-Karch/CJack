#include "card.h"
#include <stdio.h>

int main(void) {
    Card test_card = {1, HEARTS};
    printf("Testing Card: %s\n", card_to_string(test_card));
    return 0;
}
