#pragma once
#include <string>
#include <vector>

const int TRIE_DEF_ALPHABET_SIZE = 10;
class TrieDefinition {
public:
    class TrieNode {
        friend class TrieDefinition;

    public:
        // constructor
        TrieNode();
        // destructor
        ~TrieNode();

        // add index of word to vector
        void addIndex(int index);
        // remove index of word from vector
        void removeIndex(int index);
        // get vector of indexes
        std::vector<int> getIndex();

    private:
        TrieNode* mChild[TRIE_DEF_ALPHABET_SIZE];
        std::vector<int> mIndex;
    };

public:
    // constructor
    TrieDefinition();
    // destructor
    ~TrieDefinition();

    // add a part of definition into the trie (add the word corresponding to the part)
    void addPartDefinition(const std::string& definition, int index);
    // search a part of definition in the trie (search the list of words corresponding to the part)
    // return vector<index> of the word if found
    // return empty vector if not found
    std::vector<int> searchPartDefinition(const std::string& definition);
    // delete a part of definition from the trie (delete the word corresponding to the part)
    void deletePartDefinition(const std::string& definition, int index);

    // add the definition into the trie (add the word corresponding to)
    void addDefinition(const std::string& definition, int index);
    // search the definition in the trie (search the list of words corresponding to)
    // return vector<index> of the word if found
    // return empty vector if not found
    std::vector<int> searchDefinition(const std::string& definition);
    // delete the definition from the trie (delete the word corresponding to)
    void deleteDefinition(const std::string& definition, int index);

private:
    // search a definition in the trie (internal)
    // if createMode is true, create the node if not found
    // if createMode is false, return nullptr if not found
    TrieNode* internalSearchDefinition(const std::string& definition, bool createMode);

    // split the definition into a vector of strings
    std::vector<std::string> splitDefinition(const std::string& definition);

private:
    TrieNode* mRoot;
};