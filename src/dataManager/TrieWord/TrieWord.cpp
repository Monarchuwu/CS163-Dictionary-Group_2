#include "TrieWord.h"
//#include"fileWork.h"


void TrieWord::addWord(std::string word, int k) {
	Node* cur = root;
	for (int i = 0; i < word.size(); i++)
	{
		int index = word[i];
		if (!cur->child[index])
		{
			cur->child[index] = new Node;
		}
		cur = cur->child[index];
	}
	cur->id = k;
}

int TrieWord::searchWord(std::string str) {
	Node* cur = root;
	for (int i = 0; i < str.size(); i++)
	{
		int index = str[i];
		if (!cur->child[index])
		{
			return -1;
		}
		cur = cur->child[index];
	}
	return cur->id;
}

//void TrieWord::addNewWord(std::string str, std::string def) {
//	Words::Word newWord;
//	newWord.definitions.push_back(def);
//	newWord.word = str;
//
//	Dic->v.push_back(newWord);
//	int k = Dic->v.size() - 1;
//	addWord(k);
//}

void TrieWord::deleteWord(std::string str) {
	Node* cur = root;
	for (int i = 0; i < str.size(); i++)
	{
		int index = str[i];
		if (!cur->child[index])
		{
			return;
		}
		cur = cur->child[index];
	}
	cur->id = -1;
}

