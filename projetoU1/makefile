#makefile for "Projeto Unidade 1"
#created by Lucas Manoel 05/04/2024

PROG = proj 
CC = g++
CPPFLAGS = -I./headers
LDFLAGS = 
OBJS = ./bin/main.o ./bin/astronauta.o ./bin/voo.o ./bin/registro.o ./bin/interface.o

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

./bin/main.o: ./src/main.cpp
	$(CC) $(CPPFLAGS) -c ./src/main.cpp -o ./bin/main.o

./bin/astronauta.o: ./headers/astronauta.h ./src/astronauta.cpp
	$(CC) $(CPPFLAGS) -c ./src/astronauta.cpp -o ./bin/astronauta.o

./bin/voo.o: ./headers/voo.h ./src/voo.cpp
	$(CC) $(CPPFLAGS) -c ./src/voo.cpp -o ./bin/voo.o

./bin/registro.o: ./headers/registro.h ./src/registro.cpp
	$(CC) $(CPPFLAGS) -c ./src/registro.cpp -o ./bin/registro.o

./bin/interface.o: ./headers/interface.h ./src/interface.cpp
	$(CC) $(CPPFLAGS) -c ./src/interface.cpp -o ./bin/interface.o
