CC = gcc
CFLAGS = -Wall -O2 -std=c11 -fPIC
LDFLAGS = -shared
LDLIBS = -lpthread -lm

all: libvector.so app

libvector.so: vector.o
	$(CC) $(LDFLAGS) -o $@ vector.o

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c -o vector.o

app: app.o libvector.so
	$(CC) app.o -L. -lvector -Wl,-rpath=. -o app

app.o: app.c vector.h
	$(CC) $(CFLAGS) -c app.c -o app.o

clean:
	rm -f *.o *.so app