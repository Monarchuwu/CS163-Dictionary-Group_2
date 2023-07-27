#include <iostream>
#include "DataManager.h"

DataManager::DataManager()
    : mDictionary(),
      mTrieWord(&mDictionary) {
    mDataset = mModeSearch = 0;
}
DataManager::~DataManager() {}

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
    // load data from file

    // build TrieWord
    // Example:
    //delete mTrieSearchByWord;
    //mTrieSearchByWord = new searchByWord::Trie();
    //for (int i = 0; i < mWords.size(); ++i) {
    //    mTrieSearchByWord->addWord(mWords[i].mWord, i);
    //}

    // build TrieDefinition
}

void DataManager::saveDatasetInternal(const std::string& dirDataset) {
}
