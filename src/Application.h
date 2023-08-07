#pragma once
#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "Screen.h"
#include "mainScreen/ScreenMain.h"
#include "favouriteScreen/FavouriteScreen.h"
#include "addWordScreen/addWord.h"
#include "WordScreen/WordScreen.h"

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
    screen_addWord screenAddWord;
    sora::WordScreen screenWordDef;
    Screen* mScreen;
};
