#include <iostream>
#include "DataManager.h"

DataManager::DataManager()
    : mDictionary() {
    mDataset = mModeSearch = 0;
}
DataManager::~DataManager() {
    saveData();
}

void DataManager::setDataset(int dataset) {
    mDataset = dataset;
}
int DataManager::getDataset() {
    return mDataset;
}
void DataManager::setModeSearch(int modeSearch) {
    mModeSearch = modeSearch;
}
int DataManager::getModeSearch() {
    return mModeSearch;
}

void DataManager::loadData() {
    switch (mDataset) {
        case Dataset::Slang:
            loadDatasetInternal("data/slang/data.txt");
            break;

        default:
            std::cout << "[ERROR] The dataset is not available to load" << std::endl;
            break;
    }
}
void DataManager::saveData() {
    switch (mDataset) {
        case Dataset::Slang:
            saveDatasetInternal("data/slang/data.txt");
            break;

        default:
            std::cout << "[ERROR] The dataset is not available to save" << std::endl;
            break;
    }
}
void DataManager::resetData() {
    switch (mDataset) {
        case Dataset::Slang:
            loadDatasetInternal("data/slang/backup.txt");
            break;

        default:
            std::cout << "[ERROR] The dataset is not available to reset" << std::endl;
            break;
    }
}

void DataManager::loadDatasetInternal(const std::string& dirDataset) {
    std::cout << "[INFO] Loading dataset" << std::endl;
    // load data from file
    mDictionary.loadFile(dirDataset);

    // build TrieWord
    // delete mTrieSearchByWord;
    for (int i = 0; i < mDictionary.v.size(); ++i) {
        mTrieWord.addWord(mDictionary.v[i].word, i);
    }

    // build TrieDefinition
}

void DataManager::saveDatasetInternal(const std::string& dirDataset) {
    std::cout << "[INFO] Saving dataset" << std::endl;
	// save data to file
    mTrieWord.saveData(dirDataset, mDictionary);
}

Words::Word* DataManager::searchWord(const std::string& word) {
    int index = mTrieWord.searchWord(word);
    if (index == -1) return nullptr;
    return &mDictionary.v[index];
}
Words::Word* DataManager::addWord(const std::string& word) {
    int index = mTrieWord.searchWord(word);
    if (index != -1) return &mDictionary.v[index];

    Words::Word newWord;
    newWord.word = word;
    mDictionary.v.push_back(newWord);
    mTrieWord.addWord(word, (int)mDictionary.v.size() - 1);
 
    return &mDictionary.v.back();
}
void DataManager::removeWord(const std::string& word) {
    mTrieWord.deleteWord(word);
}
