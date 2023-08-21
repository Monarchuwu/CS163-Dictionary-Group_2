#pragma once
#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "../Screens/WordScreen/Screen.h"

class App {

public:
    App();

    App(int width_, int height_, std::string title);

public:
    // Run
    void run();

private:
    // Event Handler
    void processEvents();

    // Update
    void update();

    // Render
    void render();

private:
    // window
    sf::RenderWindow window;
    int width, height;

    // screens
    WordScreen::Screen wordScreen;
};