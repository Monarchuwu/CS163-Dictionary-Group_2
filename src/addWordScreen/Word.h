#pragma once
#include "function.h"

class TrieWord {
public:
    struct Node {
        Node* child[128] = { 0 };
        int id           = -1;
        // std::string str;
    };
    Node* root;
    Words Dic;
    TrieWord() {
        root = new Node;
    }
    //	void createNode();
    void addWord(int k); // k is the id in the Words.  Need to read k from Words to do addWord

    int searchWord(std::string str); // if there is none return -1.

    void addNewWord(std::string str, std::string def); // Use searchWord to know whether it is already in the Trie( Words) or not before using this

    void deleteWord(std::string str);
};

class Words {
    class Word {
    public:
        std::string word;
        std::vector<std::string> definitions;
        Word() {}
        Word(std::string w, std::vector<std::string> d) {
            this->word        = w;
            this->definitions = d;
        }
        Word(std::string w, std::string d) {
            this->word = w;
            this->definitions.push_back(d);
        }
    };

public:
    std::vector<Word> v;
    Words() {}

    void loadData(std::string& nameDict) {
        std::ifstream fin(nameDict);
        std::string word = "";
        std::string def  = "";
        std::string tmp  = "";

        while (!fin.eof()) {
            getline(fin, word, '\t');
            if (fin.eof()) return;
            getline(fin, def, '\n');

            if (word == tmp) (v.end() - 1)->definitions.push_back(def);
            else {
                Word tmp_w = Word(word, def);
                v.push_back(tmp_w);
                tmp = word;
            }
        }
    }
};
