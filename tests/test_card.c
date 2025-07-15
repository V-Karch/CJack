#include "testing_utils.h"

#include "../models/card.h"

bool test_card_create(void) {
    Card card = {1, false, HEARTS};

    // Expected
    size_t expected_value = 1;
    bool expected_drawn = false;
    Suit expected_suit = HEARTS;

    if (expected_value != card.value) { return false; }
    if (expected_drawn != card.drawn) { return false; }
    if (expected_suit != card.suit) { return false; }

    return true;
}

int main(void) {
    Test card_create = {"test_card_create()", *test_card_create};
    run_test(&card_create);
}
