cjack:
	gcc cjack.c models/card.c models/deck.c models/hand.c game/blackjack.c -o cjack

test:
	gcc tests/*.c -o cjack_tests
	./cjack_tests

clean:
	rm -f cjack cjack_tests