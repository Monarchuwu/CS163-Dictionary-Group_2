#include "Screen.h"

Screen::Screen()
	: mCallHome(false),
      mCallAddWordScreen(false),
	  mCallFavoriteList(false),
	  mCallHistoryList(false){
}

Screen::~Screen() {}

void Screen::setCallHome(bool callHome) {
	mCallHome = callHome;
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
bool Screen::getCallAddWordScreen() const {
	return mCallAddWordScreen;
}
bool Screen::getCallFavoriteList() const {
	return mCallFavoriteList;
}
bool Screen::getCallHistoryList() const {
	return mCallHistoryList;
}