CC=g++
CFLAGS=-std=c++98 -ggdb
LIBS=

Sudoku: Cluster.o Square.o Board.o Test.o tools.o
	$(CC) -o Sudoku Cluster.o Square.o Board.o Test.o tools.o $(LIBS)

Cluster.o: Cluster.cpp
	$(CC) -c Cluster.cpp $(CFLAGS)

Square.o: Square.cpp
	$(CC) -c Square.cpp $(CFLAGS)

Board.o: Board.cpp
	$(CC) -c Board.cpp $(CFLAGS)

Test.o: Test.cpp
	$(CC) -c Test.cpp $(CFLAGS)

tools.o: tools.cpp
	$(CC) -c tools.cpp $(CFLAGS)

all: Sudoku

clean: 
	rm -rf *.o
	rm -rf Cluster