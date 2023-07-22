#pragma once
#include<fstream>
#include <iostream>
#include <string>
#include <queue>
namespace minh
{
    std::string defOfWord(std::string word, const std::string& filename);

    void addToEndOfFile(std::string word, const std::string& filename, const std::string &rootfilename);

    std::string takeLine(int n, const std::string& filename);
    
    void clearFromFile(std::string word, const std::string& filename);


}