#pragma once
#include <iostream>
#include "../Constant.h"
#include "../Screen.h"
#include "Button.h"
#include "ButtonSprite.h"
#include "LineEdit.h"

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

    private:
        // color set (darkest to lightest)
        sf::Color mColor[4];

        // background
        sf::RectangleShape mBackground;

        // dataset block buttons
        Button mDatasetButton[5];
        Button* mDatasetSelected;

        // mode search block buttons
        Button mModeButton[2];
        Button* mModeSelected;

        // 4 icon buttons (features)
        ButtonSprite mPlusIcon;
        ButtonSprite mFavoriteIcon;
        ButtonSprite mHistoryIcon;
        ButtonSprite mSetDefaultIcon;

        // search line (line edit)
        LineEdit mSearchLine;

        // magnifier icon sprite
        ButtonSprite mMagnifierIcon;

        // game button
        Button mGameButton;
    };
} // namespace mainScreen