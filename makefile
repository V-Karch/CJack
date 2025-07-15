cjack:
	gcc cjack.c models/card.c models/deck.c models/hand.c -o cjack

clean:
	rm -f cjack