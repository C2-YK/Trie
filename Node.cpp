#include <string>
#include <vector>
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
    return *this;
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

Node* Node::searchNode(const std::string& s, int currentLevel){
    if(currentLevel < s.length()){
        int index = s[currentLevel] - 'a';
        if(!this->children[index]){
            return NULL;
        }
        return this->children[index]->searchNode(s, currentLevel++);
    }else{
        return this;
    }
}
bool Node::getisEndOfWord(){
    return isEndOfWord;
}

void Node::addAllChildrenWordToList(std::string s, std::vector<std::string>& l){
    if(isEndOfWord){
        l.push_back(s);
    }
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(this->children[i]){
            char c = i + 'a';
            s.append(c);
            this->children[i]->addAllChildrenWordToList(s, l);
        }
    }
}