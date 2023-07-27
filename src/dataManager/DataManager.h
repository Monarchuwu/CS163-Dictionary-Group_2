#pragma once
#include <string>
#include "TrieWord/TrieWord.h"

class DataManager {
public:
    static enum Dataset {
        EngEng,
        EngVie,
        VieEng,
        Slang,
        Emoji
    };

    static enum ModeSearch {
        SearchByWord,
        SearchByDefinition
    };

public:
    // constructor
    DataManager();

    // destructor
    ~DataManager();

    /* ----- update dataset and mode search information ----- */

    // set the dataset to load
    void setDataset(int dataset);
    // get the dataset
    int getDataset();
    // set the mode search
    void setModeSearch(int mode);
    // get the mode search
    int getModeSearch();

    /* ----- handle dataset ----- */

    // load data from file
    void loadData();
    // save data to file
    void saveData();
    // reset data to default
    /// this function will load data from backup file
    void resetData();

    /* ----- handle search word query ----- */

    /* ----- handle search definition query ----- */

private:
    // load data from file (internal)
    void loadDatasetInternal(const std::string& dirDataset);
    // save data to file (internal)
    void saveDatasetInternal(const std::string& dirDataset);

private:
    // dataset
    int mDataset;
    // mode search
    int mModeSearch;

    // store the data of dictionary
    Words mDictionary;

    // trie word
    TrieWord mTrieWord;
};
