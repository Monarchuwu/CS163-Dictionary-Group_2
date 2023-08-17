#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "../Constant.h"
#include "../Screen.h"
#include "Button.h"
#include "ButtonSprite.h"
#include "LineEdit.h"
#include "../dataManager/TrieWord/TrieWord.h"

namespace mainScreen {
    class ScreenMain : public Screen {
    public:
        // constructor
        ScreenMain();

        // destructor
        ~ScreenMain();

        // handle event
        void handleEvent(const sf::Event& event) override;

        // update
        void update() override;

        // draw
        void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

    /* Written by Sora */
    public:
        void setFirstGameButton(Words::Word* currentWord);

    private:
        sf::Color mColorBackground[5][2];

        // background
        sf::RectangleShape mBackground;
        sf::RectangleShape mBackground2;
        sf::RectangleShape mBackground3;
        sf::RectangleShape mBackground4;

        // dataset block buttons
        Button mDatasetButton[5];
        Button* mDatasetSelected;

        // mode search block buttons
        Button mModeButton[2];
        Button* mModeSelected;

        // 4 icon buttons (features)
        ButtonSprite m3DashIcon;
        ButtonSprite mPlusIcon;
        ButtonSprite mFavoriteIcon;
        ButtonSprite mHistoryIcon;
        ButtonSprite mSetDefaultIcon;

        // search line (line edit)
        LineEdit mSearchLine;

        // magnifier icon sprite
        ButtonSprite mMagnifierIcon;

        // game buttons
        Button mGameButton[3];

        /* Written by Sora */
        Box mRandomWordText;
        Box mRandomWordDefinition;
    };
} // namespace mainScreen