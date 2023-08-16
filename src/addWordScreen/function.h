#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"
#include "Button.h"
#include "Textbox.h"

#include "function.h"

bool check(std::string t);
bool inputFile(std::string& nameDict, std::string word, std::string def, int& cnt, std::string& recentword);
void outputFile(std::string& nameDict, int& cnt, std::string& recentword);
void changeLang(int dataSet, std::vector<sf::Sprite> v, sf::Sprite& lang1, sf::Sprite& lang2);
void changeText(Button& btn, int dataSet);
void checkAllDict(std::vector<std::string>& recentword_v, std::vector<int>& cnt_v, std::vector<std::string>& nameDict_v);