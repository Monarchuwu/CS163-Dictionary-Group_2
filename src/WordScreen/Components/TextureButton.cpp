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
    bool TextureButton::isHovered(float mouseX, float mouseY) {

        float btnPosX   = box.getPosition().x;
        float btnPosY   = box.getPosition().y;
        float btnWidth  = box.getLocalBounds().width;
        float btnHeight = box.getLocalBounds().height;
        return (
            btnPosX < mouseX && mouseX < btnPosX + btnWidth && btnPosY < mouseY && mouseY < btnPosY + btnHeight);
    }

    bool TextureButton::isClicked(const sf::Event& event) {
        return (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left
                && isHovered(event.mouseButton.x, event.mouseButton.y)); 
    }

    // Draw
    void TextureButton::draw(sf::RenderTarget& window) const {
        window.draw(box);
    }

    // Click event
    void TextureButton::onClick(const sf::Event& event, void (*handler)()) {
        if (isClicked(event)) {
            handler();
        }
    }
} // namespace sora