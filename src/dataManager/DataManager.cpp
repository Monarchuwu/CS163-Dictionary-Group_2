#include <iostream>
#include "DataManager.h"

DataManager::DataManager()
    : mDictionary() {
    mDataset = mModeSearch = 0;
    mTrieWord = new TrieWord();
    mTrieDefinition = new TrieDefinition();
}
DataManager::~DataManager() {
    saveData();
    delete mTrieWord;
    delete mTrieDefinition;
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
        case constant::Dataset::Slang:
            loadDatasetInternal("data/slang/data.txt");
            break;

        case constant::Dataset::Emoji:
            loadDatasetInternal("data/emoji/data.txt");
            break;

        default:
            std::cout << "[ERROR] The dataset is not available to load" << std::endl;
            break;
    }
}
void DataManager::saveData() {
    switch (mDataset) {
        case constant::Dataset::Slang:
            saveDatasetInternal("data/slang/data.txt");
            break;

        case constant::Dataset::Emoji:
            saveDatasetInternal("data/emoji/data.txt");
            break;

        default:
            std::cout << "[ERROR] The dataset is not available to save" << std::endl;
            break;
    }
}
void DataManager::resetData() {
    switch (mDataset) {
        case constant::Dataset::Slang:
            loadDatasetInternal("data/slang/backup.txt");
            break;

        case constant::Dataset::Emoji:
            loadDatasetInternal("data/emoji/backup.txt");
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
    delete mTrieWord;
    mTrieWord = new TrieWord();
    for (int i = 0; i < mDictionary.v.size(); ++i) {
        mTrieWord->addWord(mDictionary.v[i].word, i);
    }

    // build TrieDefinition
    delete mTrieDefinition;
    mTrieDefinition = new TrieDefinition();
    for (int i = 0; i < mDictionary.v.size(); ++i) {
        for (const std::string& definition : mDictionary.v[i].definitions) {
			mTrieDefinition->addDefinition(definition, i);
		}
    }
}

void DataManager::saveDatasetInternal(const std::string& dirDataset) {
    std::cout << "[INFO] Saving dataset" << std::endl;
	// save data to file
    mTrieWord->saveData(dirDataset, mDictionary);
}

Words::Word* DataManager::searchWord(const std::string& word) {
    int index = mTrieWord->searchWord(word);
    if (index == -1) return nullptr;
    return &mDictionary.v[index];
}

Words::Word* DataManager::addWord(const std::string& word) {
    int index = mTrieWord->searchWord(word);
    if (index != -1) return &mDictionary.v[index];

    Words::Word newWord(mDictionary.v.size());
    newWord.word = word;
    mDictionary.v.push_back(newWord);
    mTrieWord->addWord(word, (int)mDictionary.v.size() - 1);
 
    return &mDictionary.v.back();
}

void DataManager::removeWord(const std::string& word) {
    mTrieWord->deleteWord(word);
}

void DataManager::addDefinition(const std::string& definition, int index) {
    mTrieDefinition->addDefinition(definition, index);
}

std::vector<Words::Word*> DataManager::searchDefinition(const std::string& definition) {
    std::vector<int> list = mTrieDefinition->searchDefinition(definition);
    std::vector<Words::Word*> res;
    for (int index : list) {
		res.push_back(&mDictionary.v[index]);
	}
    return res;
}

void DataManager::deleteDefinition(const std::string& definition, int index) {
    mTrieDefinition->deleteDefinition(definition, index);
}