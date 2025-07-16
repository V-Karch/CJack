cjack:
	gcc cjack.c models/*.c game/blackjack.c -o cjack

test:
	gcc -D_GNU_SOURCE -std=c11 tests/*.c models/*.c munit/munit.c -o cjack_tests
	./cjack_tests

clean:
	rm -f cjack cjack_tests