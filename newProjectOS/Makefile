# Makfile Projet OS
# Groupe :( DE CARVALHO EDSON , WANG ALEXANDRE )
# Here you will find the makefile of our project the launch of our file copulatory and the
#lunch of the production of Doxygen documentation.
all:prog clean doxygen
utils.o : functions.h utils.h utils.c ListeBlock.o
	gcc -c utils.c
functions.o : ListeBlock.h functions.h functions.c
	gcc -c functions.c
ListeBlock.o : ListeBlock.h ListeBlock.c
	gcc -c ListeBlock.c
main.o : utils.h functions.h main.c
	gcc -c main.c
prog : main.o functions.o  utils.o
	gcc  main.o  ListeBlock.o functions.o utils.o -o prog
clean:
	rm -f utils.o functions.o main.o ListeBlock.o
doxygen :
	doxygen projectConfig