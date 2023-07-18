#include "Box.h"

namespace mainScreen {
    Box::Box(const sf::Vector2f& size)
        : sf::RectangleShape(size),
          mIsAlignCenter(false) {}

    void Box::setFont(const sf::Font& font) {
        mText.setFont(font);
    }

    void Box::setText(const std::string& text) {
        mString = text;
        mText.setString(mString);
        setTextPosition();
    }

    const std::string& Box::getText() const {
        return mString;
    }

    void Box::addChar(const sf::Uint32& c) {
        mString += c;
        mText.setString(mString);
        setTextPosition();
    }

    void Box::removeChar() {
        if (mString.size() > 0) {
            mString.pop_back();
            mText.setString(mString);
            setTextPosition();
        }
    }

    void Box::setStyle(sf::Uint32 style) {
        mText.setStyle(style);
        setTextPosition();
    }

    void Box::setCharacterSize(unsigned int size) {
        mText.setCharacterSize(size);
        setTextPosition();
    }

    void Box::setTextColor(const sf::Color& color) {
        mText.setFillColor(color);
    }

    void Box::setAlignCenter(bool alignCenter) {
        mIsAlignCenter = alignCenter;
        setTextPosition();
    }

    bool Box::getAlignCenter() const {
        return mIsAlignCenter;
    }

    void Box::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(static_cast<sf::RectangleShape>(*this), states);
        states.transform *= getTransform();
        target.draw(mText, states);
    }

    bool Box::isContain(sf::Vector2f point) const {
        point -= getPosition();
        sf::Transformable transform;
        transform.rotate(-getRotation());
        point = transform.getTransform().transformPoint(point);

        sf::FloatRect rect = getLocalBounds();
        sf::Transformable transform2;
        transform2.setScale(getScale());
        rect = transform2.getTransform().transformRect(rect);

        return rect.contains(point);
    }
    bool Box::isContain(float x, float y) const {
        return isContain(sf::Vector2f(x, y));
    }

    void Box::setTextPosition() {
        sf::FloatRect textRect = mText.getLocalBounds();
        if (mIsAlignCenter) {
            mText.setPosition(getSize().x / 2 - textRect.width / 2 - textRect.left,
                              getSize().y / 2 - textRect.height / 2 - textRect.top);
        }
        else {
            mText.setPosition(10, getSize().y / 2 - textRect.height / 2 - textRect.top);
        }
    }
} // namespace mainScreen