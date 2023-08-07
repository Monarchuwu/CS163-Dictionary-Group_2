#include "TrieDefinition.h"
#include <algorithm>
#include <iterator>

TrieDefinition::TrieNode::TrieNode() {
    // Initialize all children to nullptr
    for (int i = 0; i < TRIE_DEF_ALPHABET_SIZE; ++i) {
        mChild[i] = nullptr;
    }
}
TrieDefinition::TrieNode::~TrieNode() {
    // Delete all children
    for (int i = 0; i < TRIE_DEF_ALPHABET_SIZE; ++i) {
        if (mChild[i] != nullptr) {
            delete mChild[i];
        }
    }
}
void TrieDefinition::TrieNode::addIndex(int index) {
    if (mIndex.size() > 200) return;
    std::vector<int>::iterator it = std::lower_bound(mIndex.begin(), mIndex.end(), index);
    if (it == mIndex.end() || *it != index) {
        mIndex.insert(it, index);
    }
}
void TrieDefinition::TrieNode::removeIndex(int index) {
    std::vector<int>::iterator it = std::lower_bound(mIndex.begin(), mIndex.end(), index);
    if (it != mIndex.end() && *it == index) {
        mIndex.erase(it);
    }
}
std::vector<int> TrieDefinition::TrieNode::getIndex() {
    return mIndex;
}

TrieDefinition::TrieDefinition() {
    mRoot = new TrieNode();
}
TrieDefinition::~TrieDefinition() {
    delete mRoot;
}

void TrieDefinition::addPartDefinition(const std::string& definition, int index) {
    TrieNode* cur = internalSearchDefinition(definition, true);
    cur->addIndex(index);
}
std::vector<int> TrieDefinition::searchPartDefinition(const std::string& definition) {
    TrieNode* cur = internalSearchDefinition(definition, false);
    if (cur == nullptr) return std::vector<int>();
    return cur->getIndex();
}
void TrieDefinition::deletePartDefinition(const std::string& definition, int index) {
    TrieNode* cur = internalSearchDefinition(definition, false);
    if (cur == nullptr) return;
    cur->removeIndex(index);
}

void TrieDefinition::addDefinition(const std::string& definition, int index) {
	std::vector<std::string> parts = splitDefinition(definition);
    for (int i = 0; i < parts.size(); ++i) {
        addPartDefinition(parts[i], index);
    }
}
std::vector<int> TrieDefinition::searchDefinition(const std::string& definition) {
    std::vector<std::string> parts = splitDefinition(definition);
	std::vector<int> res;
    for (int i = 0; i < parts.size(); ++i) {
        std::vector<int> partRes = searchPartDefinition(parts[i]);
        // merge res and partRes
        std::vector<int> tmp;
        std::merge(res.begin(), res.end(), partRes.begin(), partRes.end(), std::back_inserter(tmp));
        res.swap(tmp);
    }
	return res;
}
void TrieDefinition::deleteDefinition(const std::string& definition, int index) {
    std::vector<std::string> parts = splitDefinition(definition);
    for (int i = 0; i < parts.size(); ++i) {
		deletePartDefinition(parts[i], index);
	}
}

TrieDefinition::TrieNode* TrieDefinition::internalSearchDefinition(const std::string& definition, bool createMode) {
    TrieNode* cur = mRoot;
    for (int i = 0; i < definition.size(); ++i) {
        /// CONVERT A CHAR TO [0, 9] x [0, 9]
        /// 128-ary : [32..126] per char
        /// 10-ary  : [0-9] per char
        // first, reduce [32, 126] to [0, 94]
        // then, reduce [0, 94] to [0, 9] x [0, 9]
        for (short index : { (definition[i] - 32) / 10, (definition[i] - 32) % 10 }) {
            if (cur->mChild[index] == nullptr) {
                if (createMode) {
                    cur->mChild[index] = new TrieNode();
                }
                else {
                    return nullptr;
                }
            }
            cur = cur->mChild[index];
        }
    }
    return cur;
}

std::vector<std::string> TrieDefinition::splitDefinition(const std::string& definition) {
    std::vector<std::string> res;
    std::string partDefinition = "";
    for (int k = 0; k < definition.size(); ++k) {
        if (definition[k] != ' ') partDefinition += definition[k];
        if (definition[k] == ' ' || k + 1 == (int)definition.size()) {
            if (!partDefinition.empty()) {
                res.push_back(partDefinition);
                partDefinition = "";
            }
        }
    }
    return res;
}
