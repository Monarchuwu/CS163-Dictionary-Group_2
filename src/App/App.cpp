#include "App.h"

App::App() {}

App::App(int width_, int height_, std::string title) {
    width = width_;
    height = height_;
    window.create(sf::VideoMode(width, height), title);
}

// Run
void App::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

// Event Handler
void App::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }
        wordScreen.handleEvent(window, event);
    }

}

// Update
void App::update() {
    // Screen update
    wordScreen.update();
}

// Render
void App::render() {
    window.clear(constant::BACKGROUND_COLOR);
        
    // Screen render (draw)
    wordScreen.draw(window);

    window.display();
}
