#include "models/hand.h"

int main(void) {
    srand(time(NULL)); // Set random seed each time program is run

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

    printf("\nDeck after initial draws\n");
    display_deck(deck);


    draw_next_card_to_hand(player_hand, deck);
    printf("\nTesting drawing next card to player hand\n");
    display_deck(deck);

    printf("\nPlayer hand after drawing one card\n");
    display_hand(player_hand);

    free_hand(player_hand);
    free_hand(dealer_hand);
    free(deck);

    return 0;
}
