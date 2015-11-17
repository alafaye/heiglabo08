all: horaire

horaire: main.o horaire.o
	gcc -o horaire main.o

main.o: main.c horaire.h
	gcc -o main.o -c horaire.c -W -Wall -ansi -pedantic

horaire.o: horaire.c horaire.h
	gcc -o horaire.o -c horaire.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
