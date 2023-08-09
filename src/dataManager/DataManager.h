#pragma once
#include <string>
#include "../Constant.h"
#include "TrieWord/TrieWord.h"
#include "TrieDefinition/TrieDefinition.h"

class DataManager {
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

    /* ----- handle word query ----- */
    //// return the class Word pointer if found
    //// return nullptr if not found
    Words::Word* searchWord(const std::string& word);
    //// return the class Word pointer of the new word
    Words::Word* addWord(const std::string& word);
    //// remove the word from dictionary
    void removeWord(const std::string& word);

    /* ----- handle search definition query ----- */
    // add the definition into the trie (add the word corresponding to)
    void addDefinition(const std::string& definition, int index);
    // search the definition in the trie (search the list of words corresponding to)
    // return vector<Word*> of the word if found, else return empty vector
    std::vector<Words::Word*> searchDefinition(const std::string& definition);
    // delete the definition from the trie (delete the word corresponding to)
    void deleteDefinition(const std::string& definition, int index);

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
    TrieWord* mTrieWord;
    // trie definition
    TrieDefinition* mTrieDefinition;
};
