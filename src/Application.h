#pragma once
#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "mainScreen/ScreenMain.h"

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
};
