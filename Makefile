#CS3505 2021fall
#u1230733 Christopher Chen

CC = g++
FLAG = -std=c++11 -Wall
all: TrieTest clean
TrieTest: TrieTest.o Trie.o Node.o
	$(CC) $(FLAG) -o TrieTest TrieTest.o Trie.o Node.o

TrieTest.o: TrieTest.cpp Trie.h
	$(CC) $(FLAG) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h Node.h
	$(CC) $(FLAG) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(FLAG) -c Node.cpp
clean:
	rm  *.o