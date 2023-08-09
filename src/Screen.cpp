#include "Screen.h"

Screen::Screen()
	: mCallHome(false),
      mCallAddWordScreen(false),
	  mCallFavoriteList(false),
	  mCallWordDefScreen(false) {
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

void Screen::setCallWordDefScreen(bool callWordDefScreen) {
	mCallWordDefScreen = callWordDefScreen;
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

bool Screen::getCallWordDefScreen() const {
	return mCallWordDefScreen;
}
