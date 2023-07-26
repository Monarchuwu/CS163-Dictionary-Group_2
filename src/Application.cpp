#include "Application.h"
#include <iostream>

Application::Application()
    : mWindow(),
      mScreenMain(),
      screenfav() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mWindow.create(sf::VideoMode(1600, 900), "Dictionary - Group 2", sf::Style::Close, settings);
    mWindow.setPosition(sf::Vector2i(10, 10));

    mScreen = &mScreenMain;
}

void Application::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
        }

        mScreen->handleEvent(event);
        //screenfav.handleEvent(event);
        //mScreenMain.handleEvent(event);
    }
}

void Application::update() {
    mScreen->update();

    if (mScreen->getCallHome()) {
        mScreen->setCallHome(false);
        mScreen = &mScreenMain;
        return;
    }

    if (mScreen->getCallAddWordScreen()) {
        mScreen->setCallAddWordScreen(false);
        mScreen = &screenAddWord;
        return;
    }

    if (mScreen->getCallFavoriteList()) {
        mScreen->setCallFavoriteList(false);
        mScreen = &screenfav;
        return;
    }

    //screenfav.update();
    //mScreenMain.update();
}

void Application::render() {
    mWindow.clear(sf::Color::Black);

    mScreen->draw(mWindow);
    //screenfav.draw(mWindow);
    //mScreenMain.draw(mWindow);

    mWindow.display();
}