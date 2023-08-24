#include "Word.h"

Word::Word() {

}

Word::Word(std::string newWord) {
    word = newWord;
}

void Word::addDefinition(std::string definition) {
    definitions.push_back(definition);
}

void Word::deleteDefinition(int index) {
    definitions.erase(definitions.begin() + index);
}

void Word::editDefinition(int index, std::string newDefinition) {
    if (index < 0 || index >= definitions.size()) return;
    definitions[index] = newDefinition;
}