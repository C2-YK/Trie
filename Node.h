#include <string>

const int ALPHABET_SIZE = 26;

class Node{
    Node *children[ALPHABET_SIZE];
    bool isEndOfWord;
    public:
        Node();
        ~Node();
        Node(const Node& other);
        Node& operator=(Node other);
        void addWord(const std::string& s, int currentLevel);
        bool searchWord(const std::string& s, int currentLevel);
};