/*
CS3505 2021fall
u1230733 Christopher Chen
*/
#include <string>
#include "Node.h"
#include <vector>

class Trie{
    Node *root;
    public:
        Trie();
        ~Trie();
        Trie(const Trie& other);
        Trie& operator=(Trie other);
        void addAWord(std::string s);
        bool isAWord(std::string s);
        std::vector<std::string> allWordsStartingWithPrefix(std::string s);

        
};