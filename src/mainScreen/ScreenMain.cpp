#include "ScreenMain.h"

namespace mainScreen {
    ScreenMain::ScreenMain() {
        std::cout << "[INFO] ScreenMain created\n";

        /// init color set
        {
            // EN-EN
            mColorBackground[0][0] = sf::Color(113, 114, 115);
            mColorBackground[0][1] = sf::Color(1, 49, 116);
            // EN-VN
            mColorBackground[1][0] = sf::Color(195, 44, 48);
            mColorBackground[1][1] = sf::Color(16, 13, 8);
            // VN-EN
            mColorBackground[2][0] = sf::Color(113, 114, 115);
            mColorBackground[2][1] = sf::Color(96, 13, 198);
            // SLANG
            mColorBackground[3][0] = sf::Color(113, 114, 115);
            mColorBackground[3][1] = sf::Color(238, 102, 3);
            // EMOJI
            mColorBackground[4][0] = sf::Color(113, 114, 115);
            mColorBackground[4][1] = sf::Color(52, 171, 153);
        }

        // background
        mBackground.setSize(sf::Vector2f(1600, 900));
        mBackground.setFillColor(sf::Color::White);

        mBackground2.setSize(sf::Vector2f(1600, 325));
        mBackground2.setFillColor(mColorBackground[0][0]);

        mBackground3.setSize(sf::Vector2f(1600, 225));
        mBackground3.setFillColor(mColorBackground[0][1]);

        mBackground4.setSize(sf::Vector2f(150, 205));
        mBackground4.setPosition(10, 10);
        mBackground4.setFillColor(sf::Color(255, 255, 255, 160));

        // dataset block buttons [200..1400, 50..100]
        {
            sf::Vector2f firstPos(200, 75);
            sf::Vector2f size(1200 / 5, 50);
            for (int i = 0; i < 5; ++i) {
                mDatasetButton[i].setSize(sf::Vector2f(size.x - 1, size.y));
                mDatasetButton[i].setPosition(sf::Vector2f(firstPos.x + size.x * i, firstPos.y));
                mDatasetButton[i].setFillColor(sf::Color(255, 255, 255, 80));

                mDatasetButton[i].setFont(constant::fontOpenSans);
                mDatasetButton[i].setStyle(sf::Text::Bold);
                mDatasetButton[i].setCharacterSize(30);
                mDatasetButton[i].setTextColor(sf::Color::White);
                mDatasetButton[i].setAlignCenter(true);
            }

            mDatasetButton[0].setText("EN-EN");
            mDatasetButton[1].setText("EN-VN");
            mDatasetButton[2].setText("VN-EN");
            mDatasetButton[3].setText("SLANG");
            mDatasetButton[4].setText("EMOJI");
        }
        mDatasetButton[0].setPressed(true);
        mDatasetSelected = &mDatasetButton[0];

        // mode search block buttons [500..1100, 200..250]
        {
            sf::Vector2f firstPos(530, 250);
            sf::Vector2f size(540 / 2, 50);
            for (int i = 0; i < 2; ++i) {
                mModeButton[i].setSize(sf::Vector2f(size.x - 1, size.y));
                mModeButton[i].setPosition(sf::Vector2f(firstPos.x + size.x * i, firstPos.y));
                mModeButton[i].setFillColor(sf::Color(255, 255, 255, 80));

                mModeButton[i].setFont(constant::fontOpenSans);
                mModeButton[i].setStyle(sf::Text::Bold);
                mModeButton[i].setCharacterSize(30);
                mModeButton[i].setTextColor(sf::Color::White);
                mModeButton[i].setAlignCenter(true);
            }

            mModeButton[0].setText("Word");
            mModeButton[1].setText("Definition");
        }
        mModeButton[0].setPressed(true);
        mModeSelected = &mModeButton[0];

        // 3 dashes icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("data/images/3dashes-removebg.png");
            m3DashIcon.setTexture(texture);
            m3DashIcon.setPosition(mBackground4.getPosition() + sf::Vector2f(50, 20));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            m3DashIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
        }
        // plus icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("data/images/plus-removebg.png");
            mPlusIcon.setTexture(texture);
            mPlusIcon.setPosition(mBackground4.getPosition() + sf::Vector2f(20, 80));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mPlusIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            //mPlusIcon.setColor(sf::Color(200, 200, 200));
        }
        // favorite icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("data/images/star-removebg.png");
            mFavoriteIcon.setTexture(texture);
            mFavoriteIcon.setPosition(mBackground4.getPosition() + sf::Vector2f(80, 80));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mFavoriteIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            //mFavoriteIcon.setColor(sf::Color(200, 200, 200));
        }
        // history icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("data/images/clock-removebg.png");
            mHistoryIcon.setTexture(texture);
            mHistoryIcon.setPosition(mBackground4.getPosition() + sf::Vector2f(20, 140));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mHistoryIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            //mHistoryIcon.setColor(sf::Color(200, 200, 200));
        }
        // set default icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("data/images/reverse-removebg.png");
            mSetDefaultIcon.setTexture(texture);
            mSetDefaultIcon.setPosition(mBackground4.getPosition() + sf::Vector2f(80, 140));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mSetDefaultIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            //mSetDefaultIcon.setColor(sf::Color(200, 200, 200));
        }

        // search line
        {
            mSearchLine.setSize(sf::Vector2f(500, 50));
            mSearchLine.setPosition(sf::Vector2f(550, 150));
            mSearchLine.setFillColor(sf::Color::White);
            mSearchLine.setFont(constant::fontOpenSans);
            //mSearchLine.setStyle(sf::Text::Bold);
            mSearchLine.setCharacterSize(30);
            mSearchLine.setTextColor(sf::Color::Black);
            mSearchLine.setAlignCenter(true);
        }

        // magnifier icon button sprite
        {
            sf::Texture texture;
            texture.loadFromFile("data/images/magnifier-removebg.png");
            mMagnifierIcon.setTexture(texture);
            mMagnifierIcon.setPosition(sf::Vector2f(1060, 150));

            sf::Vector2u size = texture.getSize();
            sf::Vector2f targetSize(50, 50);
            mMagnifierIcon.setScale(targetSize.x / size.x, targetSize.y / size.y);
            //mMagnifierIcon.setColor(sf::Color(200, 200, 200));
        }

        // game button
        {
            for (int i = 0; i < 3; ++i) {
                mGameButton[i].setSize(sf::Vector2f(400, 450));
                mGameButton[i].setFillColor(sf::Color(222, 222, 222));

                mGameButton[i].setFont(constant::fontOpenSans);
                mGameButton[i].setStyle(sf::Text::Bold);
                mGameButton[i].setCharacterSize(40);
                mGameButton[i].setTextColor(sf::Color::White);
                mGameButton[i].setAlignCenter(true);
                mGameButton[i].setText("Game");
            }
            mGameButton[0].setPosition(sf::Vector2f(150, 375));
            mGameButton[1].setPosition(sf::Vector2f(600, 375));
            mGameButton[2].setPosition(sf::Vector2f(1050, 375));
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

                // change 3 dashes icon status
                if (m3DashIcon.isContain(mouse.x, mouse.y)) {
                    m3DashIcon.setPressed(!m3DashIcon.getPressed());
                    std::cout << "[INFO] 3 dashes icon is clicked\n";
                }
                if (m3DashIcon.getPressed()) {
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
                        mMagnifierIcon.setPressed(true);
                        std::cout << "[INFO] Search line is not selected\n";
                    }
                    std::string text = mSearchLine.getText();
                    std::cout << "[CALL] Search text: " << text << "\n";
                }

                break;
            }

            case sf::Event::TextEntered: {
                // change search line text
                // add a char
                /// [32, 126] is the range of ASCII code of printable characters
                if (32 <= event.text.unicode && event.text.unicode <= 126) {
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
                mDatasetButton[i].setFillColor(sf::Color(255, 255, 255, 140));

                mBackground2.setSize(sf::Vector2f(1600, 325));
                mBackground2.setFillColor(mColorBackground[i][0]);

                mBackground3.setSize(sf::Vector2f(1600, 225));
                mBackground3.setFillColor(mColorBackground[i][1]);
            }
            else mDatasetButton[i].setFillColor(sf::Color(255, 255, 255, 80));
        }

        // update mode search block buttons
        for (int i = 0; i < 2; ++i) {
            if (mModeButton[i].getPressed()) {
                mModeButton[i].setFillColor(sf::Color(255, 255, 255, 140));
            }
            else mModeButton[i].setFillColor(sf::Color(255, 255, 255, 80));
        }

        if (m3DashIcon.getPressed()) {
            // update plus icon
            if (mPlusIcon.getPressed()) {
                mPlusIcon.setPressed(false);
                setCallAddWordScreen(true);
                std::cout << "[CALL] Run Plus icon feature\n";
            }
            // update favorite icon
            if (mFavoriteIcon.getPressed()) {
                mFavoriteIcon.setPressed(false);
                setCallFavoriteList(true);
                std::cout << "[CALL] Run Favorite icon feature\n";
            }
            // update history icon
            if (mHistoryIcon.getPressed()) {
                mHistoryIcon.setPressed(false);
                setCallHistory(true);
                std::cout << "[CALL] Run History icon feature\n";
            }
            // update set default icon
            if (mSetDefaultIcon.getPressed()) {
                mSetDefaultIcon.setPressed(false);
                std::cout << "[CALL] Run Set default icon feature\n";
            }
        }

        // update search line
        if (mSearchLine.getPressed()) {
            mSearchLine.setFillColor(sf::Color(222, 222, 222));
        }
        else mSearchLine.setFillColor(sf::Color::White);

        // update magnifier icon
        if (mMagnifierIcon.getPressed()) {
            std::string text = mSearchLine.getText();
            setCallSearchText(true, text);
            std::cout << "[CALL] Search text: " << text << "\n";
            mMagnifierIcon.setPressed(false);
        }
    }

    void ScreenMain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // background
        target.draw(mBackground);
        target.draw(mBackground2);
        target.draw(mBackground3);
        if (m3DashIcon.getPressed())
            target.draw(mBackground4);

        // dataset block buttons
        for (int i = 0; i < 5; ++i) {
            target.draw(mDatasetButton[i]);
        }

        // mode search block buttons
        for (int i = 0; i < 2; ++i) {
            target.draw(mModeButton[i]);
        }

        // 4 icon button (features)
        target.draw(m3DashIcon);
        if (m3DashIcon.getPressed()) {
            target.draw(mPlusIcon);
            target.draw(mFavoriteIcon);
            target.draw(mHistoryIcon);
            target.draw(mSetDefaultIcon);
        }

        // search line
        target.draw(mSearchLine);

        // lens icon sprite
        target.draw(mMagnifierIcon);

        // game button
        for (int i = 0; i < 3; ++i)
            target.draw(mGameButton[i]);
    }
} // namespace mainScreen