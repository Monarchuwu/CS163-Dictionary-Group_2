#pragma once
#include <SFML/Graphics.hpp>

class Screen {
public:
    Screen();

    virtual ~Screen();

    virtual void handleEvent(const sf::Event& event) = 0;

    virtual void update() = 0;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const = 0;

    // set call home
    void setCallHome(bool callHome);
    // set call favorite list
    void setCallFavoriteList(bool callFavoriteList);

    // get call home
    bool getCallHome() const;
    // get call favorite list
    bool getCallFavoriteList() const;

private:
    bool mCallHome;
    bool mCallFavoriteList;
};