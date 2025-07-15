cjack:
	gcc cjack.c models/card.c models/deck.c models/hand.c game/blackjack.c -o cjack

clean:
	rm -f cjack