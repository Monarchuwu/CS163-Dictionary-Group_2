#include "Screen.h"

Screen::Screen()
	: mCallHome(false),
	  mCallFavoriteList(false) {
}

Screen::~Screen() {}

void Screen::setCallHome(bool callHome) {
	mCallHome = callHome;
}
void Screen::setCallFavoriteList(bool callFavoriteList) {
	mCallFavoriteList = callFavoriteList;
}

bool Screen::getCallHome() const {
	return mCallHome;
}
bool Screen::getCallFavoriteList() const {
	return mCallFavoriteList;
}