#include "Application.h"
#include <iostream>

Application::Application()
    : mWindow(),
      mScreenMain() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mWindow.create(sf::VideoMode(1600, 900), "Dictionary - Group 2", sf::Style::Close, settings);
    mWindow.setPosition(sf::Vector2i(10, 10));
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

        mScreenMain.handleEvent(event);
    }
}

void Application::update() {
    mScreenMain.update();
}

void Application::render() {
    mWindow.clear(sf::Color::Black);

    mScreenMain.draw(mWindow);

    mWindow.display();
}