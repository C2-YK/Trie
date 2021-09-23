#include <string>
#include "Node.h"

Node::Node(){
    this->isEndOfWord = false;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        this->children[i] = NULL;
    }
}

Node::~Node(){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        delete this->children[i];
    }
}

Node::Node(const Node& other){
    this->isEndOfWord = other.isEndOfWord;

    for(int i = 0; i < ALPHABET_SIZE; i++){
        this->children[i] = NULL;
        if(other.children[i]){
            this->children[i] = new Node(*(other.children[i]));
        }
    }
}

Node& Node::operator=(Node other){
    std::swap(this->isEndOfWord, other.isEndOfWord);
    std::swap(this->children, other.children);
}

void Node::addWord(const std::string& s, int currentLevel){
    if(currentLevel < s.length()){
        int index = s[currentLevel] - 'a';
        if(!this->children[index]){
            this->children[index] = new Node();
        }
        this->children[index]->addWord(s, currentLevel++);
    }else{
        this->isEndOfWord = true;
    }
}

bool Node::searchWord(const std::string& s, int currentLevel){
    if(currentLevel < s.length()){
        int index = s[currentLevel] - 'a';
        if(!this->children[index]){
            return false;
        }
        return this->children[index]->searchWord(s, currentLevel++);
    }else{
        return this->isEndOfWord;
    }
}