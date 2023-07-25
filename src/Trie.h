#pragma once
#include <iostream>
#include <string>
#include <vector>

class Trie {
public:
    Trie* children[27] = { NULL };
    bool isWord = 0;
    std::vector<std::string> def;

    Trie() {}

    void insert(Trie* root, std::string word, std::string def) {
        for (int i = 0; i < word.length(); i++) {     
            int ind = word[i] == ' ' ? 26 : word[i] - 'a';
            if (word[i] > 'A' - 1 && word[i] < 'Z' +1) ind = word[i] - 'A';
            if (!root->children[ind]) root->children[ind] = new Trie();
            root = root->children[ind];
        }
        root->isWord = 1;
        root->def.push_back(def);
    }

    bool find(Trie* root, std::string word, std::vector<std::string>& res) {
        for (int i = 0; i < word.length(); i++) {
            int ind = word[i] == ' ' ? 26 : word[i] - 'a';
            if (word[i] > 'A' - 1 && word[i] < 'Z'+1) ind = word[i] - 'A';
            if (!root->children[ind]) return 0;
            root = root->children[ind];
        }
        if (root->isWord) {
            res = root->def;
            return 1;
        }
        return 0;
    }

    void listOut(std::vector<std::string>& res) {
        for (auto i : res) std::cout << i << " ";
    }
};