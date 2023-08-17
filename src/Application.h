#pragma once
#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "Screen.h"
#include "mainScreen/ScreenMain.h"
#include "favouriteScreen/FavouriteScreen.h"
#include "favouriteScreen/historyScreen.h"
#include "favouriteScreen/listWordScreen.h"
#include "addWordScreen/addWord.h"
#include "../src/dataManager/DataManager.h"
using namespace minh;

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow mWindow;
    mainScreen::ScreenMain mScreenMain;
    minh::ScreenFavou screenfav;
    minh::ScreenHis screenhis;
    minh::ScreenListWord screenlistword;
    screen_addWord screenAddWord;
    Screen* mScreen;

    DataManager mDataManager;
};
