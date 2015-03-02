obj = card.o common.o deck.o event.o game.o main.o memtracker.o mt19937.o seat.o standard_ai.o
head = *.h

sangusha: $(obj)
	gcc -o sanguosha $(obj)

card.o: $(head) card.c
	gcc -c card.c
common.o: $(head) common.c
	gcc -c common.c
deck.o: $(head) deck.c
	gcc -c deck.c
event.o: $(head) event.c
	gcc -c event.c
game.o: $(head) game.c
	gcc -c game.c
main.o: $(head) main.c
	gcc -c main.c
memtracker.o: $(head) memtracker.c
	gcc -c memtracker.c
mt19937.o: $(head) mt19937.c
	gcc -c mt19937.c
seat.o: $(head) seat.c
	gcc -c seat.c
standard_ai.o: $(head) standard_ai.c
	gcc -c standard_ai.c

.PHONY: clean
clean:
	-rm *.o *.obj