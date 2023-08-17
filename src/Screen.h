#pragma once
#include <SFML/Graphics.hpp>

class Screen {
public:
    Screen();

    virtual ~Screen();

    virtual void handleEvent(const sf::Event& event) = 0;

    virtual void update() = 0;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const = 0;

    // set dataset
    // data stored in Integer1
    void setDataset(bool dataset, int data = 0);
    // set modeSearch
    // data stored in Integer2
    void setModeSearch(bool modeSearch, int data = 0);

    // set call home
    void setCallHome(bool callHome);
    // set call search text
    // string in String1
    void setCallSearchText(bool callSearchText, const std::string& string = "");
    // set call add word screen
    void setCallAddWordScreen(bool callAddWordScreen);
    // set call favorite list
    void setCallFavoriteList(bool callFavoriteList);

    // set call word-definition screen
    void setCallWordDefScreen(bool callWordDefScreen);

    //set call history
    void setCallHistory(bool callHistory);

    /* WORD SCREEN */

    // set add definition
    void setAddDefinition(bool addDefinition);

    // set delete definition
    void setDeleteDefinition(bool deleteDefinition);

    // set update definition
    void setUpdateDefinition(bool updateDefinition);

    // set if favorite button is clicked (toggled)
    void setFavoriteToggled(bool favoriteToggled);

    // get dataset
    // data stored in Integer1
    bool getDataset() const;
    // get modeSearch
    // data stored in Integer2
    bool getModeSearch() const;


    // get call home
    bool getCallHome() const;
    // get call search text
    bool getCallSearchText() const;
    // get call add word screen
    bool getCallAddWordScreen() const;
    // get call favorite list
    bool getCallFavoriteList() const;

    // get call word-definition screen
    bool getCallWordDefScreen() const;

    //get call history list
    bool getCallHistoryList() const;

    // get string 1
    std::string getString1() const;
    // get integer 1
    int getInteger1() const;
    // get integer 2
    int getInteger2() const;

    /* WORD SCREEN */

    // get add definition
    bool getAddDefinition();

    // get delete definition
    bool getDeleteDefinition();

    // get update definition
    bool getUpdateDefinition();

    // get favorite toggle
    bool getFavoriteToggled();

private:
    bool mDataset;
    bool mModeSearch;
    bool mCallHome;
    bool mCallSearchText;
    bool mCallAddWordScreen;
    bool mCallFavoriteList;

    bool mCallWordDefScreen;

    bool mCallHistoryList;
    std::string mString1;
    int mInteger1;
    int mInteger2;

    /* WORD SCREEN */
    bool mAddDefinition;
    bool mDeleteDefinition;
    bool mUpdateDefinition;
    bool mFavoriteToggled;
};