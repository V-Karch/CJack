#include "blackjack.h"

void run_game() {
    srand(time(NULL));

    Card* deck = create_deck();
    shuffle_deck(deck);

    Hand* player_hand = draw_player_hand(deck);
    Hand* dealer_hand = draw_dealer_hand(deck);

    printf("Your hand:\n");
    display_hand(player_hand);
    printf("Total Value: %d\n", calculate_hand_value(player_hand));

    display_first_dealer_card(dealer_hand);
    
    printf("\nWill you hit or stand? (h/s) $ ");

    char player_choice;
    scanf("%c", &player_choice);

    if (player_choice == 'h') {
        draw_next_card_to_hand(player_hand, deck);
        printf("Your new hand:\n");
        display_hand(player_hand);

        size_t hand_value = calculate_hand_value(player_hand);
        printf("Total Value: %d\n", hand_value);

        if (hand_value > 21) {
            printf("Bust!\n");
        } else {
            printf("Dealer's Turn\n");
        }

    } else {
        draw_next_card_to_hand(dealer_hand, deck);
    }

    free(player_hand);
    free(dealer_hand);
    free(deck);
}