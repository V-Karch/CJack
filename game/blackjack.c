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

    char player_choice;
    bool player_busted = false;

    while (calculate_hand_value(player_hand) < 21) {
        printf("\nWill you hit or stand? (h/s) $ ");
        scanf(" %c", &player_choice);

        if (player_choice == 'h') {
            draw_next_card_to_hand(player_hand, deck);
            printf("Your new hand:\n");
            display_hand(player_hand);

            int hand_value = calculate_hand_value(player_hand);
            printf("Total Value: %d\n", hand_value);

            if (hand_value > 21) {
                printf("Bust! You lose.\n");
                player_busted = true;
                break;
            }

        } else if (player_choice == 's') {
            break;

        } else {
            printf("Invalid choice. Please type 'h' or 's'.\n");
        }
    }

    if (!player_busted) {
        printf("\nDealer's turn:\n");
        display_hand(dealer_hand);

        while (calculate_hand_value(dealer_hand) < 17) {
            draw_next_card_to_hand(dealer_hand, deck);
            display_hand(dealer_hand);
        }

        int player_value = calculate_hand_value(player_hand);
        int dealer_value = calculate_hand_value(dealer_hand);

        printf("Your total: %d\n", player_value);
        printf("Dealer total: %d\n", dealer_value);

        if (dealer_value > 21 || player_value > dealer_value) {
            printf("You win!\n");
        } else if (dealer_value == player_value) {
            printf("Push! It's a tie.\n");
        } else {
            printf("Dealer wins!\n");
        }
    }

    free(player_hand);
    free(dealer_hand);
    free(deck);
}
