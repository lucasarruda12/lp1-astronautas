PROG = ./main.exe
CC = g++
CPPFLAGS = -Iinclude

default: build

build:
	$(CC) $(CPPFLAGS) -o $(PROG) ./main.cpp ./src/astronauta.cpp ./src/astronoteca.cpp ./src/voo.cpp ./src/vooteca.cpp

run:
	${PROG}
