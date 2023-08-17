#include "WordScreen.h"
#include <typeinfo>

namespace sora{
    const int WordLabelWidth = 500;
    const int WordLabelHeight = 100;
    const int TextAreaWidth   = 750;
    const int TextAreaHeight  = 300;
    const int ControlButtonHeight = 50;
    const int ControlButtonWidth = 50;
    const int DefinitionButtonWidth = 250;
    const int DefinitionButtonHeight = 75;
    const int PageLabelWidth         = 250;
    const int PageLabelHeight        = 75;

    const std::string imagePath         = "data/images/WordScreen/";
    const std::string FAVORITE_STAR_IMG = "favorite_star.png";
    const std::string STAR_IMG          = "star.png";
    const std::string HOME_IMG          = "home.png";
    const std::string DELETE_IMG        = "delete.png";

    /* BUTTON EVENTS */


    // Constructor
    WordScreen::WordScreen() {
        std::cout << "[WORD SCREEN] Created!" << std::endl;

        wordText = Label("Cat", WordLabelWidth, WordLabelHeight, 48, constant::fontArial);
        wordText.setStyle(sf::Text::Bold | sf::Text::Italic);
        changeWord("interchangeable");

        pageText = Label("1/8", PageLabelWidth, PageLabelHeight, 28, constant::fontArial);
        pageText.setStyle(sf::Text::Bold);
        setPage();


        definitionText = TextArea(TextAreaWidth, TextAreaHeight, 24, constant::fontArial);
        definitionText.setPosition(constant::appWidth / 2 - TextAreaWidth / 2, 300);
        definitionText.setContent("Temp");

        prevBtn = WordButton("<", ControlButtonHeight, ControlButtonWidth, 24, constant::fontArial, constant::WHITE, constant::BLACK);
        prevBtn.setPosition(constant::appWidth / 2 - TextAreaWidth / 2 - ControlButtonWidth - 30, 300 + TextAreaHeight / 2 - ControlButtonHeight / 2);

        nextBtn = WordButton(">", ControlButtonHeight, ControlButtonWidth, 24, constant::fontArial, constant::WHITE, constant::BLACK);
        nextBtn.setPosition(constant::appWidth / 2 + TextAreaWidth / 2 + 30, 300 + TextAreaHeight / 2 - ControlButtonHeight / 2);
    
        favoriteBtn.setSize(50, 50);
        favoriteBtn.setTextureByLink(imagePath + FAVORITE_STAR_IMG);
        favoriteBtn.setPosition(20, 20);

        starBtn.setSize(50, 50);
        starBtn.setTextureByLink(imagePath + STAR_IMG);
        starBtn.setPosition(20, 20);
        
        homeBtn.setSize(50, 50);
        homeBtn.setTextureByLink(imagePath + HOME_IMG);
        homeBtn.setPosition(100, 20);

        wordDeleteButton.setSize(50, 50);
        wordDeleteButton.setTextureByLink(imagePath + DELETE_IMG);
        wordDeleteButton.setPosition(180, 20);

        addDefBtn = WordButton("New Definition", DefinitionButtonWidth, DefinitionButtonHeight, 24, constant::fontArial, constant::WHITE, constant::BLACK);     
        addDefBtn.setPosition(constant::appWidth / 2 - TextAreaWidth / 2, 750);

        deleteDefBtn = WordButton("Remove Definition", DefinitionButtonWidth, DefinitionButtonHeight, 24, constant::fontArial, constant::WHITE, constant::BLACK);     
        deleteDefBtn.setPosition(constant::appWidth / 2 + TextAreaWidth / 2 - DefinitionButtonWidth, 750);

    }

    // Destructor
    WordScreen::~WordScreen() {
        std::cout << "[WORD SCREEN] Deleted!" << std::endl;
    }

    // Event Handler
    void WordScreen::handleEvent(sf::RenderWindow &window, sf::Event &event) {
        

    }

    // Update
    void WordScreen::update() {
        if (!isActive) {
            return;
        }
    }

    // Draw

    void WordScreen::handleEvent(const sf::Event &event) {
        if (!isActive) {
            return;
        }

        definitionText.onClick(event);
        definitionText.onType(event);
        if (event.type == sf::Event::TextEntered) {
            int key = event.text.unicode;
            if (key == ENTER_KEY) updateDefinition();
        }
        if (definitionText.isOutClicked(event)) updateDefinition();

        if (homeBtn.isClicked(event)) returnHomeScreen();

        if (favoriteBtn.isClicked(event) && isFavorite) toggleFavorite();
        else if (starBtn.isClicked(event) && !isFavorite) toggleFavorite();

        if (prevBtn.isClicked(event)) prevDefinition();

        if (nextBtn.isClicked(event)) nextDefinition();

        if (wordDeleteButton.isClicked(event)) deleteWord();

        if (addDefBtn.isClicked(event)) addDefinition();

        if (deleteDefBtn.isClicked(event)) deleteDefinition();
    }

    void WordScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const {
        if (!isActive) {
            window.clear(constant::BACKGROUND_COLOR);
            return;
        }
        window.clear(constant::BACKGROUND_COLOR);
        wordText.draw(window);
        definitionText.draw(window);
        prevBtn.draw(window);
        nextBtn.draw(window);
        homeBtn.draw(window);
        wordDeleteButton.draw(window);
        if (isFavorite)
            favoriteBtn.draw(window);
        else
            starBtn.draw(window);
        addDefBtn.draw(window);
        deleteDefBtn.draw(window);
        pageText.draw(window);
    }

    void WordScreen::changeWord(std::string text) {
        wordText.setContent(text);
        int X = constant::appWidth / 2 - WordLabelWidth / 2;
        int Y = 20;
        wordText.setPosition(X, Y);
    }

    void WordScreen::changeDefinition(std::string text) {
        definitionText.setContent(text);
    }

    // Return to Home Screen
    void WordScreen::returnHomeScreen() {
        setCallHome(true);
        std::cout << "Heading back to [HOME SCREEN]...\n";
        // isActive = false;
    }

    void WordScreen::prevDefinition() {
        if (!currentWord) return;
        --currentId;
        if (currentId < 0) currentId += currentWord->definitions.size();
        setDefinition();
    }

    void WordScreen::nextDefinition() {
        if (!currentWord) return;
        ++currentId;
        if (currentId == currentWord->definitions.size()) currentId = 0;
        setDefinition();
    }

    void WordScreen::setDefinition() {
        changeDefinition(currentWord->definitions[currentId]);
        setPage();
    }

    void WordScreen::setCurrentIndex(int index) {
        currentId = index;
    }

    void WordScreen::setFavorite(bool type) {
        isFavorite = type;
    }

    bool WordScreen::getFavorite() {
        return isFavorite;
    }

    void WordScreen::toggleFavorite() {
        setFavorite(!isFavorite);
        setFavoriteToggled(true);
    }

    void WordScreen::setPage() {
        int X = constant::appWidth / 2 - PageLabelWidth / 2;
        int Y = 650;
        pageText.setPosition(X, Y);

        if (!currentWord) return;
        std::string page;
        page = std::to_string(currentId + 1) + "/" + std::to_string(currentWord->definitions.size());
        pageText.setContent(page);
    }

    void WordScreen::addDefinition() {
        setAddDefinition(true);
    }

    void WordScreen::deleteDefinition() {
        setDeleteDefinition(true);
    }

    void WordScreen::setWord(Words::Word *&wordPointer) {
        currentWord = wordPointer;

        changeWord(currentWord->word);
        currentId = 0;
        setDefinition();
    }

    Words::Word *WordScreen::getWord() {
        return currentWord;
    }

    std::string WordScreen::getCurrentDefinition() {
        return definitionText.getContent();
    }

    int WordScreen::getCurrentIndex() {
        return currentId;
    }

    // Database interaction
    void WordScreen::updateDefinition() {
        if (currentWord->definitions[currentId] != getCurrentDefinition()) {
            setUpdateDefinition(true);
        }
    }

    void WordScreen::deleteWord() {
        if (!currentWord) return;
        std::cout << "[WORD SCREEN] You have deleted " + currentWord->word << std::endl;
        returnHomeScreen();
    }
}