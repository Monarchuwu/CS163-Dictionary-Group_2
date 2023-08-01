#include "Screen.h"

Screen::Screen()
    : mCallHome(false),
      mCallSearchText(false),
      mCallAddWordScreen(false),
	  mCallFavoriteList(false),
	  mCallHistoryList(false){
}

Screen::~Screen() {}

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
bool Screen::getCallHistoryList() const {
	return mCallHistoryList;
}
std::string Screen::getString1() const {
	return mString1;
}