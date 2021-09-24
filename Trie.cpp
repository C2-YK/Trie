/*
CS3505 2021fall
u1230733 Christopher Chen
*/
#include <string>
#include <vector>
#include "Trie.h"

Trie::Trie(){
    this->root = new Node();
}

Trie::~Trie(){
    delete this->root;
}

Trie::Trie(const Trie& other){
    this->root = new Node(*(other.root));
}

Trie& Trie::operator=(Trie other){
    std::swap(this->root, other.root);
    return *this;
}

void Trie::addAWord(std::string s){
    this->root->addWord(s, 0);
}

bool Trie::isAWord(std::string s){
    return (*this->root->searchNode(s, 0)).getisEndOfWord();
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string s){
    std::vector<std::string> words = {};
    //Find the starting node base on pass in prefix
    Node startingNode = *this->root->searchNode(s,0);
    //From the starting node get all children word
    startingNode.addAllChildrenWordToList(s, words);
    return words;
}