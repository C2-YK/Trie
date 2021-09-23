#include <string>
#include "Node.h"
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
}

void Trie::addAWord(std::string s){
    this->root->addWord(s, 0);
}

bool Trie::isAWord(std::string s){
    this->root->searchWord(s, 0);
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string s){

}