#pragma once
#include <string>
#include <vector>

class Word {
public:
    Word();

    Word(std::string newWord);

public:
    void addDefinition(std::string definition);

    void deleteDefinition(int index);

    void editDefinition(int index, std::string newDefinition);

public:
    std::string word;
    std::vector<std::string> definitions;
    int id;
};