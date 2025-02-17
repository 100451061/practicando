all: hola_mundo

hola_mundo: hola_mundo.o
	gcc -o hola_mundo hola_mundo.o -lc

hola_mundo.o: hola_mundo.c
	gcc -c hola_mundo.c

clean:
	rm -f hola_mundo hola_mundo.o

