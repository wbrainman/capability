all:	install

CC = gcc

INCLUDE = .

INSTDIR	= $(PWD)/  

main:	main.c cap.c cap.h setEther.c setEther.h
	$(CC) -o main main.c cap.c cap.h setEther.c setEther.h -lcap 

Robb:	Robb.c cap.c cap.h setEther.c setEther.h
	$(CC) -o Robb Robb.c  cap.c cap.h setEther.c setEther.h -lcap 

Sansa:	Sansa.c cap.c cap.h
	$(CC) -o Sansa Sansa.c  cap.c cap.h -lcap

Arya:	Arya.c cap.c cap.h
	$(CC) -o Arya Arya.c  cap.c cap.h  -lcap


clean:

install:	main	Robb Sansa	Arya
	
