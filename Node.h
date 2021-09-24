#include <string>
#include <vector>

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
        Node* searchNode(const std::string& s, int currentLevel);
        bool getisEndOfWord();
        void addAllChildrenWordToList(std::string s, std::vector<std::string>& l);
};