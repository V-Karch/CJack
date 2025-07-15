#include "models/hand.h"

int main(void) {
    Card* deck = create_deck();
    printf("Unshuffled Deck:\n");
    display_deck(deck);

    shuffle_deck(deck);
    printf("\nShuffed Deck:\n");
    display_deck(deck);

    Hand* player_hand = draw_player_hand(deck);
    Hand* dealer_hand = draw_dealer_hand(deck);

    printf("\nInitial Player Hand:\n");
    display_hand(player_hand);

    printf("\nInitial Dealer Hand:\n");
    display_hand(dealer_hand);

    free_hand(player_hand);
    free_hand(dealer_hand);
    free(deck);

    return 0;
}
