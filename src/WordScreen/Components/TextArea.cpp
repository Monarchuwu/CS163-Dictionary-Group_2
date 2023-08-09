#include "TextArea.h"

namespace sora {
    // Content
    void TextArea::setContent(std::string text) {
        content = text;
        setDisplayText();
    }

    // Add character
    void TextArea::addContent(char t) {
        content += t;
        setDisplayText();
    }

    // Remove Character
    void TextArea::deleteContent() {
        if (content.empty()) return;
        content.pop_back();
        setDisplayText();
    }

    // Font
    void TextArea::setFont(sf::Font &font) {
        textHolder.setFont(font);
    }

    // Text Size
    void TextArea::setTextSize(int size) {
        textHolder.setCharacterSize(size);
    }

    // Text color
    void TextArea::setTextColor(sf::Color color) {
        textHolder.setFillColor(color);
    }

    // Get content
    std::string TextArea::getContent() {
        return content;
    }

    // Focus and Blur
    void TextArea::setFocus(bool type) {
        isFocused = type;
        setDisplayText();
    }

    void TextArea::setDisplayText() {
        std::string display_text = "";

        int length         = content.length();
        float boxWidth     = box.getLocalBounds().width;
        float currentWidth = 0;

        sf::Text text;
        text.setFont(*(textHolder.getFont()));

        std::string word;
        std::stringstream ss(content);

        while (std::getline(ss, word, ' ')) {
            // store token string in the vector
            text.setString(word);
            display_text += word;
            display_text += ' ';
            int wordWidth = text.getLocalBounds().width;
            if (currentWidth + wordWidth < boxWidth) {
                currentWidth += wordWidth + 10;
            }
            else {
                currentWidth = 0;
                display_text += '\n';
            }
        }

        if (display_text[display_text.size() - 1] == ' ') display_text.pop_back();
        if (content[content.size() - 1] == ' ') display_text.push_back(' ');
        if (isFocused) {
            if (display_text.empty()) display_text = "_";
            else display_text.push_back('_');
        }

        textHolder.setString(display_text);
    }

    // Box
    // Input size
    void TextArea::setSize(int width, int height) {
        sf::Vector2f size(width, height);
        box.setSize(size);
    }

    // Background Color
    void TextArea::setBackgroundColor(sf::Color color) {
        box.setFillColor(color);
    }

    // Position
    void TextArea::setPosition(int x, int y) {
        box.setPosition(x, y);

        float textX = x + 10;
        float textY = y + box.getLocalBounds().height / 100;
        textHolder.setPosition(textX, textY);
    }

    // TextArea
    TextArea::TextArea() {}

    TextArea::TextArea(int width, int height, int textSize, sf::Font &font, sf::Color textColor, sf::Color bgColor) {
        setFont(font);
        setTextSize(textSize);
        setTextColor(textColor);

        setSize(width, height);
        setBackgroundColor(bgColor);

        setContent("Hello");
    }

    // Draw
    void TextArea::draw(sf::RenderTarget &window) const {
        window.draw(box);
        window.draw(textHolder);
    }

    // Check mouse over
    bool TextArea::isHovered(float mouseX, float mouseY) {
        float posX   = box.getPosition().x;
        float posY   = box.getPosition().y;
        float width  = box.getLocalBounds().width;
        float height = box.getLocalBounds().height;
        return (
            posX < mouseX && mouseX < posX + width && posY < mouseY && mouseY < posY + height);
    }

    bool TextArea::getFocused() { return isFocused; }

    // Click event
    void TextArea::onClick(const sf::Event &event) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (isHovered(event.mouseButton.x, event.mouseButton.y)) {
                    setFocus(true);
                }
                else {
                    setFocus(false);
                }
            }
        }
    }

    void TextArea::onType(const sf::Event &event) {
        if (!isFocused) return;
        if (event.type == sf::Event::TextEntered) {
            int key = event.text.unicode;
            switch (key) {
                case ENTER_KEY:
                    setFocus(false);
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

    bool TextArea::isClicked(const sf::Event &event) {
        return (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left
                && isHovered(event.mouseButton.x, event.mouseButton.y)); 
    }

    bool TextArea::isOutClicked(const sf::Event &event) {
        return (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left
                && !isHovered(event.mouseButton.x, event.mouseButton.y)); 
    }
} // namespace sora