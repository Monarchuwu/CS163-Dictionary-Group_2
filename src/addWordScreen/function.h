#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"
#include "Button.h"
#include "Textbox.h"

void inputFile(Trie* root, std::string& nameDict, std::string word, std::string def, int& cnt, std::string& recentword);
void outputFile(Trie* root, std::string& nameDict, int& cnt, std::string& word);
void changeLang(int i, std::vector<sf::Sprite> v, sf::Sprite& lang1, sf::Sprite& lang2);
void changeText(Button& btn, int lr);
void checkAllDict(std::vector<std::string>& recentword_v, std::vector<int>& cnt_v, std::vector<std::string>& nameDict_v, Trie* root);