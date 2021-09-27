CC = gcc
CFLAGS = -O2 -lm -fopenmp

all:	testando

testando: main.o ferramentas.o
	$(CC) $(CFLAGS) -o testando ferramentas.o main.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

ferramentas.o: ferramentas.c
	$(CC) $(CFLAGS) -o ferramentas.o -c ferramentas.c

clean: 
	rm *.o
	rm testando