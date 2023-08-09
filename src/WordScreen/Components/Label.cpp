#include "Label.h"

namespace sora {
    // Content
    void Label::setContent(std::string text) {
        content = text;
        textHolder.setString(content);
    }

    // Font
    void Label::setFont(sf::Font &font) {
        textHolder.setFont(font);
    }

    // Text Size
    void Label::setTextSize(int size) {
        textHolder.setCharacterSize(size);
    }

    // Text color
    void Label::setTextColor(sf::Color color) {
        textHolder.setFillColor(color);
    }

    // Box
    // Input size
    void Label::setSize(int width, int height) {
        sf::Vector2f size(width, height);
        box.setSize(size);
    }

    // Background Color
    void Label::setBackgroundColor(sf::Color color) {
        box.setFillColor(color);
    }

    // Position
    void Label::setPosition(int x, int y) {
        box.setPosition(x, y);

        float textX = x + box.getLocalBounds().width / 2 - textHolder.getLocalBounds().width / 2;
        float textY = y + box.getLocalBounds().height / 2 - textHolder.getLocalBounds().height / 1.5;

        textHolder.setPosition(textX, textY);
    }

    void Label::setStyle(sf::Uint32 style) {
        textHolder.setStyle(style);
    }

    // Label
    Label::Label() {}

    Label::Label(std::string title, int width, int height, int textSize, sf::Font &font, sf::Color textColor, sf::Color bgColor) {
        setFont(font);
        setTextSize(textSize);
        setTextColor(textColor);
        setContent(title);

        setSize(width, height);
        setBackgroundColor(bgColor);
    }

    // Draw
    void Label::draw(sf::RenderTarget &window) const {
        window.draw(box);
        window.draw(textHolder);
    }

    // Check mouse over
    bool Label::isHovered(sf::RenderTarget &window) {
        float mouseX = sf::Mouse::getPosition().x;
        float mouseY = sf::Mouse::getPosition().y;

        float posX   = box.getPosition().x;
        float posY   = box.getPosition().y;
        float width  = box.getLocalBounds().width;
        float height = box.getLocalBounds().height;
        return (
            posX < mouseX && mouseX < posX + width && posY < mouseY && mouseY < posY + height);
    }
} // namespace sora