#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Words {

public:
    class Word {
    public:
        int index;
        std::string word;
        std::vector<std::string> definitions;

        Word(int index) { this->index = index; }

        Word(std::string w, std::vector<std::string> d, int index) {
            this->word = w;
            this->definitions = d;
            this->index       = index;
        }

        Word(std::string w, std::string d, int index) {
            this->word = w;
            this->definitions.push_back(d);
            this->index = index;
        }

        int getIndex() {
			return this->index;
        }
    };


    std::vector<Word> v;
    Words() {}

    void loadFile(std::string nameDict) {
        v.clear();

        std::ifstream fin(nameDict);
        std::string word = "";
        std::string def = "";
        std::string tmp = "";

        while (!fin.eof()) {
            getline(fin, word, '\t');
            if (fin.eof()) return;
            getline(fin, def, '\n');

            if (word == tmp) (v.end() - 1)->definitions.push_back(def);
            else {
                Word tmp_w = Word(word, def, v.size());
                v.push_back(tmp_w);
                tmp = word;
            }
        }
    };

    void printOut() {
        for (auto i : v) {
            std::cout << i.word << " ";
            for (auto j : i.definitions)  std::cout << j << " ";
            std::cout << std::endl;
        }
    }
};

class TrieWord
{
	struct Node
	{
		Node* child[128] = { 0 };
		int id = -1;
		//std::string str;

        ~Node() {
            for (int i = 0; i < 128; ++i) {
                if (child[i] != 0) {
                    delete child[i];
                }
            }
        }
	};

private:
	Node* root;

public:
 
    TrieWord() {
		root = new Node;
	}

    ~TrieWord() {
		delete root;
	}

	//	void createNode();
	void addWord(std::string str, int k);// k is the id in the Words.  Need to read k from Words to do addWord

	int searchWord(std::string str);// if there is none return -1.

	//void addNewWord(std::string str, std::string def);// Use searchWord to know whether it is already in the Trie( Words) or not before using this

	void deleteWord(std::string str);

    void recursive(TrieWord::Node* cur, const Words& Dic, std::ofstream& ft) {
		for (int i = 0; i < 128; i++) {
            if (cur->child[i]) {
                if (cur->child[i]->id != -1) {
                    for (auto j : Dic.v[cur->child[i]->id].definitions) ft << Dic.v[cur->child[i]->id].word << "\t" << j << "\n";
                }
                recursive(cur->child[i], Dic, ft);
            }
		}
	}

	void saveData(std::string nameDict, const Words& Dic) {
		std::ofstream ft(nameDict);

		recursive(root, Dic, ft);
	}
};
