#include "MyTrie.h"
#include"fileWork.h"


void Trie::addWord(int k)
{
	Words::Word tu = Dic.v[k];
	Node* cur = root;
	for (int i = 0; i < tu.word.size(); i++)
	{
		int index = tu.word[i];
		if (!cur->child[index])
		{
			cur->child[index] = new Node;
		}
		cur = cur->child[index];
	}
	cur->id = k;
}

int Trie::searchWord(std::string str)
{
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

void Trie::addNewWord(std::string str, std::string def)
{
	Words::Word newWord;
	newWord.definitions.push_back(def);
	newWord.word = str;

	Dic.v.push_back(newWord);
	int k = Dic.v.size() - 1;
	addWord(k);
}

void Trie::deleteWord(std::string str)
{
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

