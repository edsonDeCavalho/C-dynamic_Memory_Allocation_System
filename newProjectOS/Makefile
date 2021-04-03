# Makfile Projet OS
# Groupe :( DE CARVALHO EDSON , WANG ALEXANDRE )
# Here you will find the makefile of our project the launch of our file copulatory and the
#lunch of the production of Doxygen documentation.
all:prog clean doxygen
utils.o : functions.h utils.h utils.c
	gcc -c utils.c
functions.o : aboutDataStructure.h functions.h functions.c
	gcc -c functions.c
aboutDataStructure.o : aboutDataStructure.h aboutDataStructure.c
	gcc -c aboutDataStructure.c
main.o : utils.h functions.h aboutDataStructure.h  main.c
	gcc -c main.c
prog : main.o aboutDataStructure.o functions.o  utils.o
	gcc  main.o aboutDataStructure.o functions.o utils.o -o prog
clean:
	rm -f utils.o functions.o aboutDataStructure.o main.o
doxygen :
	doxygen projectConfig