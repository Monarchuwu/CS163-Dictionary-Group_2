#include "ScreenMain.h"

namespace mainScreen {
    ScreenMain::ScreenMain() {
        std::cout << "[INFO] ScreenMain created\n";

        // init color set
        mColor[0] = sf::Color(0, 28, 48);
        mColor[1] = sf::Color(23, 107, 135);
        mColor[2] = sf::Color(100, 204, 197);
        mColor[3] = sf::Color(218, 255, 251);

        // background
        mBackground.setSize(sf::Vector2f(1600, 900));
        mBackground.setFillColor(mColor[0]);

        // dataset block buttons [200..1400, 100..150]
        {
            sf::Vector2f firstPos(200, 100);
            sf::Vector2f size(1200 / 5, 50);
            for (int i = 0; i < 5; ++i) {
                mDatasetButton[i].setSize(sf::Vector2f(size.x - 1, size.y));
                mDatasetButton[i].setPosition(sf::Vector2f(firstPos.x + size.x * i, firstPos.y));
                mDatasetButton[i].setFillColor(mColor[1]);

                mDatasetButton[i].setFont(constant::fontArial);
                mDatasetButton[i].setStyle(sf::Text::Bold);
                mDatasetButton[i].setCharacterSize(30);
                mDatasetButton[i].setTextColor(sf::Color::Black);
                mDatasetButton[i].setAlignCenter(true);
            }

            mDatasetButton[0].setText("EngEng");
            mDatasetButton[1].setText("EngVie");
            mDatasetButton[2].setText("VieEng");
            mDatasetButton[3].setText("Slang");
            mDatasetButton[4].setText("Emoji");
        }
        mDatasetButton[0].setPressed(true);
        mDatasetSelected = &mDatasetButton[0];

        // mode search block buttons [500..1100, 200..250]
        {
            sf::Vector2f firstPos(500, 200);
            sf::Vector2f size(600 / 2, 50);
            for (int i = 0; i < 2; ++i) {
                mModeButton[i].setSize(sf::Vector2f(size.x - 1, size.y));
                mModeButton[i].setPosition(sf::Vector2f(firstPos.x + size.x * i, firstPos.y));
                mModeButton[i].setFillColor(mColor[1]);

                mModeButton[i].setFont(constant::fontArial);
                mModeButton[i].setStyle(sf::Text::Bold);
                mModeButton[i].setCharacterSize(30);
                mModeButton[i].setTextColor(sf::Color::Black);
                mModeButton[i].setAlignCenter(true);
            }

            mModeButton[0].setText("Search Word");
            mModeButton[1].setText("Search by Definition");
        }
        mModeButton[0].setPressed(true);
        mModeSelected = &mModeButton[0];

        /*
        // plus icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("Resources/plus3-icon - Copy.png");
            mPlusIcon.setTexture(texture);
            mPlusIcon.setPosition(sf::Vector2f(1200, 200));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mPlusIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            mPlusIcon.setColor(mColor[2]);
        }
        // favorite icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("Resources/star-icon - Copy.png");
            mFavoriteIcon.setTexture(texture);
            mFavoriteIcon.setPosition(sf::Vector2f(1250, 200));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mFavoriteIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            mFavoriteIcon.setColor(mColor[2]);
        }
        // history icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("Resources/book-icon - Copy.png");
            mHistoryIcon.setTexture(texture);
            mHistoryIcon.setPosition(sf::Vector2f(1300, 200));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mHistoryIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            mHistoryIcon.setColor(mColor[2]);
        }
        // set default icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("Resources/clean-icon - Copy.png");
            mSetDefaultIcon.setTexture(texture);
            mSetDefaultIcon.setPosition(sf::Vector2f(1350, 200));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mSetDefaultIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            mSetDefaultIcon.setColor(mColor[2]);
        }
        */

        // search line
        {
            mSearchLine.setSize(sf::Vector2f(500, 50));
            mSearchLine.setPosition(sf::Vector2f(520, 300));
            mSearchLine.setFillColor(mColor[1]);
            mSearchLine.setFont(constant::fontArial);
            mSearchLine.setStyle(sf::Text::Bold);
            mSearchLine.setCharacterSize(30);
            mSearchLine.setTextColor(sf::Color::Black);
            mSearchLine.setAlignCenter(true);
        }

        /*
        // magnifier icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("Resources/magnifier - Copy.png");
            mMagnifierIcon.setTexture(texture);
            mMagnifierIcon.setPosition(sf::Vector2f(1030, 300));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mMagnifierIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            mMagnifierIcon.setColor(mColor[2]);
        }
        */

        // game button
        {
            mGameButton.setSize(sf::Vector2f(500, 300));
            mGameButton.setPosition(sf::Vector2f(550, 450));
            mGameButton.setFillColor(mColor[1]);

            mGameButton.setFont(constant::fontArial);
            mGameButton.setStyle(sf::Text::Bold);
            mGameButton.setCharacterSize(40);
            mGameButton.setTextColor(sf::Color::Black);
            mGameButton.setAlignCenter(true);
            mGameButton.setText("Game");
        }
    }

    ScreenMain::~ScreenMain() {
        std::cout << "[INFO] ScreenMain destroyed\n";
    }

    void ScreenMain::handleEvent(const sf::Event& event) {
        switch (event.type) {
            case sf::Event::MouseButtonReleased: {
                sf::Event::MouseButtonEvent mouse = event.mouseButton;

                // change dataset (dataset block buttons)
                for (int i = 0; i < 5; ++i) {
                    if (mDatasetButton[i].isContain(mouse.x, mouse.y)) {
                        mDatasetSelected->setPressed(false);
                        mDatasetSelected = &mDatasetButton[i];
                        mDatasetSelected->setPressed(true);
                        std::cout << "[INFO] Dataset " << i + 1 << " selected\n";
                        break;
                    }
                }

                // change mode search (mode search block buttons)
                for (int i = 0; i < 2; ++i) {
                    if (mModeButton[i].isContain(mouse.x, mouse.y)) {
                        mModeSelected->setPressed(false);
                        mModeSelected = &mModeButton[i];
                        mModeSelected->setPressed(true);
                        std::cout << "[INFO] Mode Search " << i + 1 << " selected\n";
                        break;
                    }
                }

                // change plus icon status
                if (mPlusIcon.isContain(mouse.x, mouse.y)) {
                    mPlusIcon.setPressed(true);
                    std::cout << "[INFO] Plus icon is clicked\n";
                }
                // change favorite icon status
                if (mFavoriteIcon.isContain(mouse.x, mouse.y)) {
                    mFavoriteIcon.setPressed(true);
                    std::cout << "[INFO] Favorite icon is clicked\n";
                }
                // change history icon status
                if (mHistoryIcon.isContain(mouse.x, mouse.y)) {
                    mHistoryIcon.setPressed(true);
                    std::cout << "[INFO] History icon is clicked\n";
                }
                // change set default icon status
                if (mSetDefaultIcon.isContain(mouse.x, mouse.y)) {
                    mSetDefaultIcon.setPressed(true);
                    std::cout << "[INFO] Set default icon is clicked\n";
                }

                // change search line status
                if (mSearchLine.isContain(mouse.x, mouse.y)) {
                    mSearchLine.setPressed(true);
                    std::cout << "[INFO] Search line is selected\n";
                }
                else if (mSearchLine.getPressed()) {
                    mSearchLine.setPressed(false);
                    std::cout << "[INFO] Search line is not selected\n";
                }

                // change magnifier icon status
                if (mMagnifierIcon.isContain(mouse.x, mouse.y)) {
                    mMagnifierIcon.setPressed(true);
                    std::cout << "[INFO] Magnifier icon is selected\n";
                }

                break;
            }

            case sf::Event::KeyReleased: {
                // change search line text
                // remove a char
                if (event.key.code == sf::Keyboard::BackSpace) {
                    if (mSearchLine.getPressed()) {
                        mSearchLine.removeChar();
                        std::cout << "[INFO] Search line removes a char\n";
                    }
                }

                // search the text in search line by enter
                if (event.key.code == sf::Keyboard::Enter) {
                    if (mSearchLine.getPressed()) {
                        mSearchLine.setPressed(false);
                        std::cout << "[INFO] Search line is not selected\n";
                    }
                    std::string text = mSearchLine.getText();
                    std::cout << "[CALL] Search text: " << text << "\n";
                }
            }

            case sf::Event::TextEntered: {
                // change search line text
                // add a char
                if ('a' <= event.text.unicode && event.text.unicode <= 'z' || event.text.unicode == ' ') {
                    if (mSearchLine.getPressed()) {
                        mSearchLine.addChar(event.text.unicode);
                        std::cout << "[INFO] Search line adds a char"
                                  << " (" << event.text.unicode << ")\n";
                    }
                }
                break;
            }

            default:
                break;
        }
    }

    void ScreenMain::update() {
        // update dataset block buttons
        for (int i = 0; i < 5; ++i) {
            if (mDatasetButton[i].getPressed()) {
                mDatasetButton[i].setFillColor(mColor[2]);
            }
            else mDatasetButton[i].setFillColor(mColor[1]);
        }

        // update mode search block buttons
        for (int i = 0; i < 2; ++i) {
            if (mModeButton[i].getPressed()) {
                mModeButton[i].setFillColor(mColor[2]);
            }
            else mModeButton[i].setFillColor(mColor[1]);
        }

        // update plus icon
        if (mPlusIcon.getPressed()) {
            mPlusIcon.setPressed(false);
            std::cout << "[CALL] Run Plus icon feature\n";
        }
        // update favorite icon
        if (mFavoriteIcon.getPressed()) {
            mFavoriteIcon.setPressed(false);
            std::cout << "[CALL] Run Favorite icon feature\n";
        }
        // update history icon
        if (mHistoryIcon.getPressed()) {
            mHistoryIcon.setPressed(false);
            std::cout << "[CALL] Run History icon feature\n";
        }
        // update set default icon
        if (mSetDefaultIcon.getPressed()) {
            mSetDefaultIcon.setPressed(false);
            std::cout << "[CALL] Run Set default icon feature\n";
        }

        // update search line
        if (mSearchLine.getPressed()) {
            mSearchLine.setFillColor(mColor[2]);
        }
        else mSearchLine.setFillColor(mColor[1]);

        // update magnifier icon
        if (mMagnifierIcon.getPressed()) {
            std::string text = mSearchLine.getText();
            std::cout << "[CALL] Search text: " << text << "\n";
            mMagnifierIcon.setPressed(false);
        }
    }

    void ScreenMain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // background
        target.draw(mBackground);

        // dataset block buttons
        for (int i = 0; i < 5; ++i) {
            target.draw(mDatasetButton[i]);
        }

        // mode search block buttons
        for (int i = 0; i < 2; ++i) {
            target.draw(mModeButton[i]);
        }

        // 4 icon button (features)
        target.draw(mPlusIcon);
        target.draw(mFavoriteIcon);
        target.draw(mHistoryIcon);
        target.draw(mSetDefaultIcon);

        // search line
        target.draw(mSearchLine);

        // lens icon sprite
        target.draw(mMagnifierIcon);

        // game button
        target.draw(mGameButton);
    }
} // namespace mainScreen