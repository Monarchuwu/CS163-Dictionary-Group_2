#pragma once
#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "Screen.h"
#include "mainScreen/ScreenMain.h"
#include "favouriteScreen/FavouriteScreen.h"
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
    Screen* mScreen;
};