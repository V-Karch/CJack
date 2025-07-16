#include "hand.h"

Hand* draw_player_hand(Card* deck) {
    // Players cards will always be drawn first
    set_card_drawn(deck, 0);
    set_card_drawn(deck, 1);

    Hand* hand = malloc(sizeof(Hand));
    hand->length = 2;
    hand->hand = malloc(2 * sizeof(Card));

    hand->hand[0] = deck[0];
    hand->hand[1] = deck[1];

    return hand;
} // Remember to free the associated memory later

Hand* draw_dealer_hand(Card* deck) {
    // Dealers cards will always be drawn second
    set_card_drawn(deck, 2);
    set_card_drawn(deck, 3);

    Hand* hand = malloc(sizeof(Hand));
    hand->length = 2;
    hand->hand = malloc(2 * sizeof(Card));

    hand->hand[0] = deck[2];
    hand->hand[1] = deck[3];

    return hand;
} // Remember to free the associated memory later

void display_hand(Hand* hand) {
    for (int i = 0; i < hand->length; i++) {
        if (i == hand->length - 1) {
            char* card_string = card_to_string(hand->hand[i]);
            printf("%s.\n", card_string);
            free(card_string);
        } else {
            char* card_string = card_to_string(hand->hand[i]);
            printf("%s, ", card_string);
            free(card_string);
        }
    }
}

void display_first_dealer_card(Hand *hand) {
    char* dealer_card_string = card_to_string(hand->hand[0]);
    printf("\nThe dealer's first card:\n");
    printf("%s\n", dealer_card_string);

    Hand fake_hand = {1, &hand->hand[0]};
    printf("Value: %d\n", calculate_hand_value(&fake_hand));

    free(dealer_card_string);
}

void free_hand(Hand* hand) {
    free(hand->hand);
    free(hand);
}

void draw_next_card_to_hand(Hand* hand, Card* deck) {
    int index = find_next_undrawn_card(deck);
    if (index == -1) {
        set_all_cards_undrawn(deck);
        shuffle_deck(deck);
        // TODO: Maybe redraw hands and find some way to continue
        // Idk how you would get to this point in the first place
        // That the entire deck needs to be reshuffled
        // due to having too many cards listed as drawn
    } else {
        set_card_drawn(deck, index);
        hand->length++;
        hand->hand = realloc(hand->hand, hand->length * sizeof(Card));
        hand->hand[hand->length - 1] = deck[index];
    }
}

size_t calculate_hand_value(Hand *hand) {
    size_t sum = 0;
    size_t ace_count = 0;

    for (size_t i = 0; i < hand->length; i++) {
        size_t card_value = hand->hand[i].value;
        if (card_value == 1) {
            ace_count++;
            sum += 11;
            continue; 
            // Skip to next loop if there's an Ace
        } 
    
        if (card_value >= 10) {
            sum += 10; // All face cards are 10
        } else {
            sum += card_value; // Add non-face card value
        }
    }

    while (sum > 21 && ace_count > 0) {
        // If aces are present and sum is a bust
        // Turn ace from 11 into 1
        // If still bust, repeat
        sum -= 10;
        ace_count--;
    }

    return sum;
}
