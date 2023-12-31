#include "Screen.h"

Screen::Screen()
    : mDataset(false),
      mModeSearch(false),
      mCallHome(false),
      mCallSearchText(false),
      mCallAddWordScreen(false),
      mCallFavoriteList(false),
      mCallWordDefScreen(false),
      mCallHistoryList(false),
      mCallDefaultDataset(false),
      mAddDefinition(false),
      mDeleteDefinition(false),
      mUpdateDefinition(false),
      mFavoriteToggled(false),
      mDeleteWord(false),
      mCallAddWord(false),
      mCallGameScreen(false) {
}

Screen::~Screen() {}

void Screen::setDataset(bool dataset, int data) {
    this->mDataset  = dataset;
    this->mInteger1 = data;
}
void Screen::setModeSearch(bool modeSearch, int data) {
    this->mModeSearch = modeSearch;
    this->mInteger2   = data;
}
void Screen::setCallHome(bool callHome) {
	mCallHome = callHome;
}
void Screen::setCallSearchText(bool callSearchText, const std::string& string) {
	mCallSearchText = callSearchText;
	mString1 = string;
}
void Screen::setCallAddWordScreen(bool callAddWordScreen) {
	mCallAddWordScreen = callAddWordScreen;
}
void Screen::setCallFavoriteList(bool callFavoriteList) {
	mCallFavoriteList = callFavoriteList;
}
void Screen::setCallHistory(bool callHistoryList){
	mCallHistoryList = callHistoryList;
}
void Screen::setCallAddWord(bool callAddWord, const std::string& w, const std::string& d) {
    mCallAddWord = callAddWord;
    mString1     = w;
    mString2     = d;
}
void Screen::setCallGameScreen(bool callGameScreen) {
    mCallGameScreen = callGameScreen;
}
void Screen::setCallGameScreen2(bool callGameScreen) {
    mCallGameScreen2 = callGameScreen;
}
void Screen::setDefaultDataset(bool callDefaultDataset) {
	mCallDefaultDataset = callDefaultDataset;
}

/* WORD SCREEN */

void Screen::setAddDefinition(bool addDefinition) {
	mAddDefinition = addDefinition;
}
void Screen::setDeleteDefinition(bool deleteDefinition) {
	mDeleteDefinition = deleteDefinition;
}
void Screen::setUpdateDefinition(bool updateDefinition) {
	mUpdateDefinition = updateDefinition;
}
void Screen::setFavoriteToggled(bool favoriteToggled) {
	mFavoriteToggled = favoriteToggled;
}
void Screen::setDeleteWord(bool deleteWord) {
	mDeleteWord = deleteWord;
}
void Screen::setCallWordDefScreen(bool callWordDefScreen) {
	mCallWordDefScreen = callWordDefScreen;
}

bool Screen::getDataset() const {
	return this->mDataset;
}
bool Screen::getModeSearch() const {
	return this->mModeSearch;
}

bool Screen::getCallHome() const {
	return mCallHome;
}
bool Screen::getCallSearchText() const {
	return mCallSearchText;
}
bool Screen::getCallAddWordScreen() const {
	return mCallAddWordScreen;
}
bool Screen::getCallFavoriteList() const {
	return mCallFavoriteList;
}
bool Screen::getCallWordDefScreen() const {
	return mCallWordDefScreen;
}
bool Screen::getCallHistoryList() const {
	return mCallHistoryList;
}
bool Screen::getCallAddWord() const {
    return mCallAddWord;
}
bool Screen::getCallGameScreen() const {
    return mCallGameScreen;
}
bool Screen::getCallGameScreen2() const {
    return mCallGameScreen2;
}
bool Screen::getCallDefaultDataset() const {
	return mCallDefaultDataset;
}

std::string Screen::getString1() const {
	return mString1;
}
std::string Screen::getString2() const {
    return mString2;
}
int Screen::getInteger1() const {
	return this->mInteger1;
}
int Screen::getInteger2() const {
	return this->mInteger2;
}

bool Screen::getAddDefinition() {
	return mAddDefinition;
}

bool Screen::getDeleteDefinition() {
	return mDeleteDefinition;
}

bool Screen::getUpdateDefinition() {
	return mUpdateDefinition;
}

bool Screen::getFavoriteToggled() {
	return mFavoriteToggled;
}

bool Screen::getDeleteWord() {
	return mDeleteWord;
}

