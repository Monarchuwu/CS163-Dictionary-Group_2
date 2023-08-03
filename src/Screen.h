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
    //set call history
    void setCallHistory(bool callHistory);

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
    //get call history list
    bool getCallHistoryList() const;

    // get string 1
    std::string getString1() const;
    // get integer 1
    int getInteger1() const;
    // get integer 2
    int getInteger2() const;

private:
    bool mDataset;
    bool mModeSearch;
    bool mCallHome;
    bool mCallSearchText;
    bool mCallAddWordScreen;
    bool mCallFavoriteList;
    bool mCallHistoryList;
    std::string mString1;
    int mInteger1;
    int mInteger2;
};