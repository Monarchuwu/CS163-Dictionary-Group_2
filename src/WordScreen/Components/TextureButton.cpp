#include "TextureButton.h"

namespace sora {
    TextureButton::TextureButton() {}

    TextureButton::TextureButton(int width, int height) {
        setSize(width, height);
    }

    // Button Size
    void TextureButton::setSize(int width, int height) {
        sf::Vector2f size(width, height);
        box.setSize(size);
    }

    // Texture
    void TextureButton::setTextureByLink(std::string link) {
        if (!texture.loadFromFile(link)) {
            std::cout << "Cannot load image from " << link << std::endl;
        }
        else {
            box.setTexture(&texture);
        }
    }

    // Position
    void TextureButton::setPosition(int x, int y) {
        box.setPosition(x, y);
    }

    // Check mouse over
    bool TextureButton::isHovered(sf::RenderWindow& window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX   = box.getPosition().x;
        float btnPosY   = box.getPosition().y;
        float btnWidth  = box.getLocalBounds().width;
        float btnHeight = box.getLocalBounds().height;
        return (
            btnPosX < mouseX && mouseX < btnPosX + btnWidth && btnPosY < mouseY && mouseY < btnPosY + btnHeight);
    }

    bool TextureButton::isClicked(sf::RenderWindow& window) {
        return (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isHovered(window));
    }

    // Draw
    void TextureButton::draw(sf::RenderWindow& window) {
        window.draw(box);
    }

    // Click event
    void TextureButton::onClick(sf::RenderWindow& window, void (*handler)()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isHovered(window)) {
            handler();
        }
    }
} // namespace sora