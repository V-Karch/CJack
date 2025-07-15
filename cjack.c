#include <stdio.h>
#include <stdlib.h>

#include "models/card.h"
#include "models/deck.h"
#include "models/hand.h"

int main(void) {
    Card* deck = create_deck();
    printf("Unshuffled Deck:\n");
    display_deck(deck);

    shuffle_deck(deck);
    printf("\nShuffed Deck:\n");
    display_deck(deck);

    Card* player_hand = draw_player_hand(deck);
    Card* dealer_hand = draw_dealer_hand(deck);

    printf("\nPlayer's Initial Hand:\n");
    char* player_first_card = card_to_string(player_hand[0]);
    char* player_second_card = card_to_string(player_hand[1]);
    printf("%s, %s.\n", player_first_card, player_second_card);

    printf("\nDealer's Initial Hand:\n");
    char* dealer_first_card = card_to_string(dealer_hand[0]);
    char* dealer_second_card = card_to_string(dealer_hand[1]);
    printf("%s, %s.\n", dealer_first_card, dealer_second_card);

    printf("\nDeck After Dealing Initial Hands:\n");
    display_deck(deck);

    free(deck);

    free(player_first_card);
    free(player_second_card);
    free(dealer_first_card);
    free(dealer_second_card);

    free(player_hand);
    free(dealer_hand);

    return 0;
}
