typedef enum {
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS
} Suite;

typedef struct {
    int value;
    Suite suite;
} Card;

char* suite_to_string(Suite suite);
char* card_to_string(Card card);