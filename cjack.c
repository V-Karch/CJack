#include "models/hand.h"

int main(void) {
    srand(time(NULL)); // Set random seed each time program is run

    Card* deck = create_deck();
    shuffle_deck(deck);

    Hand* player_hand = draw_player_hand(deck);
    Hand* dealer_hand = draw_dealer_hand(deck);

    printf("\nInitial Player Hand:\n");
    printf("Hand Value: %d\n", calculate_hand_value(player_hand));
    display_hand(player_hand);

    printf("\nInitial Dealer Hand:\n");
    printf("hand Value: %d\n", calculate_hand_value(dealer_hand));
    display_hand(dealer_hand);

    free_hand(player_hand);
    free_hand(dealer_hand);
    free(deck);

    return 0;
}
