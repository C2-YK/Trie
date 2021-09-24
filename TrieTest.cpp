#include "Trie.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> readFileToVector(const std::string& filename)
{
    std::ifstream source;
    source.open(filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(source, line))
    {
        lines.push_back(line);
    }
    return lines;
}

int main(int argc, char **argv){
    std::string wordsFilename(argv[1]);
    std::string queriesFilename(argv[2]);
    std::vector<std::string> words = readFileToVector(wordsFilename);
    std::vector<std::string> queries = readFileToVector(queriesFilename);

    Trie t;

    for(int i = 0; i < words.size(); i++){
        t.addAWord(words[i]);
    }

    for(int i = 0; i < queries.size(); i++){
        if(t.isAWord(queries[i])){
            std::cout << "word is found" << std::endl;
        }else{
            std::cout << "word is not found, did you mean:" << std::endl;
            std::vector<std::string> l = t.allWordsStartingWithPrefix(queries[i]);
            if(l.size() == 0)
                std::cout << "   no alternatives found" << std::endl;
            else{
                for(int m = 0; m < l.size(); m++){
                    std::cout << "   "<< l[m] << std::endl;
                }
            }
        }
    }
    return 0;
}