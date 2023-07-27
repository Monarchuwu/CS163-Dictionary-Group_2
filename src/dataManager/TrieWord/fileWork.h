#pragma once
#include<fstream>
#include <iostream>
#include <string>
#include <queue>
#include "TrieWord.h"

namespace minh
{
    std::string defOfWord(std::string word, const std::string& filename);

    void addToEndOfFile(int id, const std::string& filename, std::vector<Words::Word> v);

    std::string takeLine(int n, const std::string& filename);
    
    void clearFromFile(std::string word, const std::string& filename);


}