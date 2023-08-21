#include "Input.h"

namespace sora {
    // Content
    void Input::setContent(std::string text) {
        content = text;
        setDisplayText();
    }

    // Add character
    void Input::addContent(char t) {
        content += t;
        setDisplayText();
    }

    // Remove Character
    void Input::deleteContent() {
        if (content.empty()) return;
        content.pop_back();
        setDisplayText();
    }

    // Font
    void Input::setFont(sf::Font &font) {
        textHolder.setFont(font);
    }

    // Text Size
    void Input::setTextSize(int size) {
        textHolder.setCharacterSize(size);
    }

    // Text color
    void Input::setTextColor(sf::Color color) {
        textHolder.setFillColor(color);
    }

    // Focus and Blur
    void Input::setFocus(bool type) {
        isFocused = type;
        setDisplayText();
    }

    void Input::setDisplayText() {
        std::string display_text = content;
        if (display_text.empty() || isFocused) display_text += "_";
        textHolder.setString(display_text);
    }

    // Box
    // Input size
    void Input::setSize(int width, int height) {
        sf::Vector2f size(width, height);
        box.setSize(size);
    }

    // Background Color
    void Input::setBackgroundColor(sf::Color color) {
        box.setFillColor(color);
    }

    // Position
    void Input::setPosition(int x, int y) {
        box.setPosition(x, y);

        float textX = x + 10;
        float textY = y + box.getLocalBounds().height / 2 - textHolder.getLocalBounds().height / 1.5;

        textHolder.setPosition(textX, textY);
    }

    // Input
    Input::Input() {}
    Input::Input(int width, int height, int textSize, sf::Font &font, sf::Color textColor, sf::Color bgColor) {
        setFont(font);
        setTextSize(textSize);
        setTextColor(textColor);
        setContent("Hello");

        setSize(width, height);
        setBackgroundColor(bgColor);
    }

    // Draw
    void Input::draw(sf::RenderWindow &window) {
        window.draw(box);
        window.draw(textHolder);
    }

    // Check mouse over
    bool Input::isHovered(sf::RenderWindow &window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float posX   = box.getPosition().x;
        float posY   = box.getPosition().y;
        float width  = box.getLocalBounds().width;
        float height = box.getLocalBounds().height;
        return (
            posX < mouseX && mouseX < posX + width && posY < mouseY && mouseY < posY + height);
    }

    // Click event
    void Input::onClick(sf::RenderWindow &window, sf::Event &event) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (isHovered(window)) {
                    setFocus(true);
                }
                else {
                    setFocus(false);
                }
            }
        }
    }

    void Input::onType(sf::RenderWindow &window, sf::Event &event) {
        if (!isFocused) return;
        if (event.type == sf::Event::TextEntered) {
            int key = event.text.unicode;
            switch (key) {
                case ENTER_KEY:
                    std::cout << "You have searched: " + content << std::endl;
                    break;
                case ESCAPE_KEY:
                    setFocus(false);
                    break;
                case DELETE_KEY:
                    deleteContent();
                    break;
                default:
                    addContent(key);
            }
        }
    }
} // namespace sora