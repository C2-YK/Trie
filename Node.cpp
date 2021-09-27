/*
CS3505 2021fall
u1230733 Christopher Chen
*/
#include <string>
#include <vector>
#include "Node.h"
#include <iostream>

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
/*
This is a recursion method, travel through the nodes, adding children if children doesn't exsit,
if reach the last char in string s then mark current node as isEndOfWord = true.
currentLevel indecate the depth of the node, for example: root/starting point = 0.
*/
void Node::addWord(const std::string& s, int currentLevel){
    if(currentLevel < s.length()){
        int index = s[currentLevel] - 'a';
        if(!this->children[index]){
            this->children[index] = new Node();
        }
        this->children[index]->addWord(s, currentLevel+1);
    }else{
        this->isEndOfWord = true;
    }
}
/*
This is a recursion method, it will search the node base on the pass in path(string s)
, return NULL if can't find the target node.
currentLevel indecate the depth of the node, for example: root/starting point = 0.
*/
Node* Node::searchNode(const std::string& s, int currentLevel){
    if(currentLevel < s.length()){
        int index = s[currentLevel] - 'a';
        if(!this->children[index]){
            return NULL;
        }
        return this->children[index]->searchNode(s, currentLevel+1);
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
            this->children[i]->addAllChildrenWordToList(s+c, l);
        }
    }
}