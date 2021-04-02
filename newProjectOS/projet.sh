#!/bin/sh

if [ ! -e $1 ]
then
  echo "Fichier $1 inexistant"
  exit 0
fi
if [ ! -r $1 ]
then
  echo "Fichier $1.c inaccessible en lecture"
  chmod u+r $1
  exit 0
fi

./main instructions.txt

exit 0