#include "./WordButton.h"

namespace sora {
    // Content
    void WordButton::setContent(std::string content) {
        text.setString(content);
    }

    // Font
    void WordButton::setFont(sf::Font& font) {
        text.setFont(font);
    }

    // Button Size
    void WordButton::setSize(int width, int height) {
        sf::Vector2f size(width, height);
        box.setSize(size);
    }

    // Text Size
    void WordButton::setTextSize(int size) {
        text.setCharacterSize(size);
    }

    // Background Color
    void WordButton::setBackgroundColor(sf::Color color) {
        box.setFillColor(color);
    }

    // Text Color
    void WordButton::setTextColor(sf::Color color) {
        text.setFillColor(color);
    }

    // Position
    void WordButton::setPosition(int x, int y) {
        box.setPosition(x, y);

        float textX = x + box.getLocalBounds().width / 2 - text.getLocalBounds().width / 2;
        float textY = y + box.getLocalBounds().height / 2 - text.getLocalBounds().height / 1.5;

        text.setPosition(textX, textY);
    }

    // Check mouse over
    bool WordButton::isHovered(float mouseX, float mouseY) {
        float btnPosX   = box.getPosition().x;
        float btnPosY   = box.getPosition().y;
        float btnWidth  = box.getGlobalBounds().width;
        float btnHeight = box.getGlobalBounds().height;
        return (
            btnPosX < mouseX && mouseX < btnPosX + btnWidth && btnPosY < mouseY && mouseY < btnPosY + btnHeight);
    }

    bool WordButton::isClicked(const sf::Event& event) {
        return (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left
                && isHovered(event.mouseButton.x, event.mouseButton.y)); 
    }

    WordButton::WordButton() {}

    WordButton::WordButton(std::string title, int width, int height, int textSize, sf::Font& font, sf::Color bgColor, sf::Color textColor) {
        setFont(font);
        setContent(title);
        setTextSize(textSize);
        setTextColor(textColor);

        setSize(width, height);
        setBackgroundColor(bgColor);
    }

    // Draw
    void WordButton::draw(sf::RenderTarget& window) const {
        window.draw(box);
        window.draw(text);
    }

    // Click event
    void WordButton::onClick(const sf::Event& event, void (*handler)()) {
        if (isClicked(event)) {
            handler();
        }
    }
} // namespace sora