#include "Application.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Application::Application()
    : mWindow(),
      mScreenMain(),
      screenfav() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mWindow.create(sf::VideoMode(1600, 900), "Dictionary - Group 2", sf::Style::Close, settings);
    mWindow.setPosition(sf::Vector2i(10, 10));

    mDataManager.setDataset(constant::Dataset::EngEng);
    mDataManager.setModeSearch(constant::ModeSearch::SearchByWord);
    mDataManager.loadData();
    screenfav.changeDir(constant::Dataset::EngEng);
    screenhis.changeDir(constant::Dataset::EngEng);

    mScreen = &mScreenMain;
    mScreen->setCallHome(true);

    srand(time(0));
}

void Application::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
        }

        mScreen->handleEvent(event);
        //screenfav.handleEvent(event);
        //mScreenMain.handleEvent(event);
    }
}

void Application::update() {
    // handle dataset and mode search
    { 
        if (mScreen->getDataset()) {
            int dataset = mScreen->getInteger1();
            mScreen->setDataset(false);
            if (dataset != mDataManager.getDataset()) {
                mDataManager.saveData();
                mDataManager.setDataset(dataset);
                mDataManager.loadData();
                screenfav.changeDir(dataset);
                screenhis.changeDir(dataset);
                std::cout << "[INFO] Change dataset to " << dataset << std::endl;
                mScreen->setCallHome(true);
            }
            return;
        }
        if (mScreen->getModeSearch()) {
            int modeSearch = mScreen->getInteger2();
            mScreen->setModeSearch(false);
            if (modeSearch != mDataManager.getModeSearch()) {
                mDataManager.setModeSearch(modeSearch);
                std::cout << "[INFO] Change modeSearch to " << modeSearch << std::endl;
            }
            return;
        }
    }

    // HOME SCREEN CALL
    if (mScreen->getCallHome()) {
        mScreen->setCallHome(false);
        mScreen = &mScreenMain;


        Words::Word* randomWord = mDataManager.getRandomWord();
        if (randomWord) {
            //std::cout << randomWord->word << "\n";
            mScreenMain.setFirstGameButton(randomWord);
        }
    }

    // ADD WORD SCREEN
    else if (mScreen->getCallAddWordScreen()) {
        mScreen->setCallAddWordScreen(false);
        mScreen = &screenAddWord;
    }

    // FAVORITE SCREEN CALL
    else if (mScreen->getCallFavoriteList()) {
        mScreen->setCallFavoriteList(false);
        mScreen = &screenfav;
    }

    // HISTORY SCREEN CALL
    else if (mScreen->getCallHistoryList()) {
        mScreen->setCallHistory(false);
        mScreen = &screenhis;
        return;
    }

    // SEARCH TEXT -> WORD-DEFINITION SCREEN CALL
    else if (mScreen->getCallSearchText()) {
        if (mDataManager.getModeSearch() == constant::ModeSearch::SearchByWord) {
			std::cout << "[INFO] Search by word" << std::endl;

			// run search word
			std::string word = mScreen->getString1();
			mScreen->setCallSearchText(false);

			// go to word screen if word exists
			Words::Word* currrentWord = mDataManager.searchWord(word);
			if (currrentWord != nullptr) {
                std::cout << "[WORD FOUND] " + currrentWord->word << "\n";

                bool isFavorite = screenfav.inTheFile(currrentWord->word);
                screenhis.addAWord(currrentWord->word);

                // Open the Word-Definition screen
                if (mScreen->getCallWordDefScreen()) {
                    mScreen->setCallWordDefScreen(false);
                    mScreen = &screenWordDef;

                    screenWordDef.setWord(currrentWord);
                    screenWordDef.setFavorite(isFavorite);
                }
			}
			else {
                std::cout << "Not found word\n";
			}
        }
        else {
			std::cout << "[INFO] Search by definition" << std::endl;
			// run search definition
			std::string word = mScreen->getString1();
			mScreen->setCallSearchText(false);
			// go to word list screen
			std::vector<Words::Word*> listWord = mDataManager.searchDefinition(word);
			std::vector<std::string> listWordStr;
			for (Words::Word*& wordPtr : listWord) {
                listWordStr.push_back(wordPtr->word);
			}
			screenlistword.setListWord(listWordStr);
			mScreen = &screenlistword;
			return;
        }
    }
    
    /* WORD SCREEN EVENT */
    if (mScreen->getUpdateDefinition()) {
        mScreen->setUpdateDefinition(false);

        Words::Word* currentWord  = screenWordDef.getWord();
        if (currentWord) {
            std::string newDefinition = screenWordDef.getCurrentDefinition();
            std::string oldDefinition = currentWord->definitions[screenWordDef.getCurrentIndex()];
             std::cout << oldDefinition << " -> " << newDefinition << "\n";

            if (oldDefinition != newDefinition) {
                mDataManager.updateDefinition(oldDefinition, newDefinition, currentWord->index);
            }
        }
    }

    if (mScreen->getAddDefinition()) {
        mScreen->setAddDefinition(false);

        Words::Word* currentWord = screenWordDef.getWord();
        if (currentWord) {
            mDataManager.addDefinition("", currentWord->index);
            screenWordDef.setCurrentIndex(currentWord->definitions.size() - 1);
            screenWordDef.setDefinition();
        }
    }

    if (mScreen->getDeleteDefinition()) {
        mScreen->setDeleteDefinition(false);
        
        Words::Word* currentWord = screenWordDef.getWord();
        if (currentWord) {
            std::string definition = screenWordDef.getCurrentDefinition();
            mDataManager.deleteDefinition(definition, currentWord->index);

            if (currentWord->definitions.size() == 0) {
                currentWord->definitions.push_back("");
            }

            else if (screenWordDef.getCurrentIndex() == currentWord->definitions.size()) {
                screenWordDef.setCurrentIndex(currentWord->definitions.size() - 1);
            }
            screenWordDef.setDefinition();
        }
    }

    if (mScreen->getFavoriteToggled()) {
        mScreen->setFavoriteToggled(false);

        Words::Word* currentWord = screenWordDef.getWord();
        bool isFavorite          = screenWordDef.getFavorite();
        if (isFavorite) {
            screenfav.addAWord(currentWord->word);
        }
        else {
            screenfav.deleteAWord(currentWord->word);
        }
    }

    if (mScreen->getDeleteWord()) {
        mScreen->setDeleteWord(false);
        std::cout << "Delete word\n";
        Words::Word* currentWord = screenWordDef.getWord();
        if (currentWord) {
            int index = currentWord->index;
            for (std::string defintion : currentWord->definitions) {
                mDataManager.deleteDefinition(defintion, index);
            }
            mDataManager.removeWord(currentWord->getIndex());
        }

        mScreen->setCallHome(true);
    }

    /* --------------------------------------------------- */

    if (mScreen->getCallDefaultDataset()) {
        mScreen->setDefaultDataset(false);
        mDataManager.resetData();
        return;
    }
    
    if (mScreen->getCallAddWordScreen()) {
        mScreen->setCallAddWordScreen(false);
        mScreen = &screenAddWord;
        screenAddWord.setDataSet(mDataManager.getDataset());
        return;
    }

    if (mScreen->getCallAddWord()) {      
        std::string word = mScreen->getString1();
        std::string def  = mScreen->getString2();
        Words::Word* w   = mDataManager.addWord(word);
        mDataManager.addDefinition(def, w->getIndex());
        mScreen->setCallAddWord(false);
        return;
    }

    if (mScreen->getCallGameScreen()) {
        mScreen->setCallGameScreen(false);
        mScreen = &screenGame;
        screenGame.setDataSet(mDataManager.getDataset(), 0);
        return;
    }

    if (mScreen->getCallGameScreen2()) {
        mScreen->setCallGameScreen2(false);
        mScreen = &screenGame;
        screenGame.setDataSet(mDataManager.getDataset(), 1);
        return;
    }

    mScreen->update();
    // screenfav.update();
    //mScreenMain.update();

}

void Application::render() {
    mWindow.clear(sf::Color::Black);

    mScreen->draw(mWindow);
    //screenfav.draw(mWindow);
    //mScreenMain.draw(mWindow);

    mWindow.display();
}