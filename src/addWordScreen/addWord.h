#pragma once
#include "../Screen.h"
#include "Trie.h"
#include "Button.h"
#include "Textbox.h"
#include "function.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class screen_addWord : public Screen {
public:
    sf::RectangleShape head;

    sf::Font roboto;

    sf::Texture eule;
    sf::Texture pink;
    sf::Texture orange;
    sf::Texture lightvi;
    sf::Texture bluevi;
    sf::Texture vn;
    sf::Texture eng;
    sf::Texture home;

    sf::Sprite eules;
    sf::Sprite pinks;
    sf::Sprite oranges;
    sf::Sprite lightvis;
    sf::Sprite bluevis;
    sf::Sprite vns;
    sf::Sprite engs;
    sf::Sprite homes;

    Textbox textbox1;
    Textbox textbox2;
    Button btn1;
    Button btnWord;
    Button btnDef;
    Button total;
    Button recent; 

    const std::string pathImage = ".\\data\\images\\";
    const std::string pathFont = ".\\data\\fonts\\";
    const std::string pathData= ".\\data\\datas\\";

    std::vector<sf::Sprite> sprite_v;
    std::vector<sf::Color> color_v = { sf::Color::Color(77, 171, 135, 255), sf::Color::Color(253, 99, 190, 255), sf::Color::Color(254,144,83,255), sf::Color::Color(153,142,232,255), sf::Color::Color(96, 13, 198, 255) };
    std::vector<sf::Sprite> sprite_lang_v;
    std::vector<std::string> recentword_v;
    std::vector<int> cnt_v;
    std::vector<std::string> nameDict_v = { pathData + "Eng-Eng.txt", pathData + "Eng-Vi.txt", pathData + "Vi-Eng.txt", pathData + "Emoji.txt", pathData + "Slang.txt" };

    Textbox* tmp = &textbox1;
    Trie* root = new Trie();
    sf::Sprite sprite_tmp;
    sf::Color color_tmp;
    int lr = 0;
    std::string nameDict = pathData+"Eng-Eng.txt";
    sf::Sprite lang1;
    sf::Sprite lang2;

    sf::RectangleShape background;

    //constructor
    screen_addWord() : background(sf::Vector2f(1600, 900)) {
        //Head
        head.setSize(sf::Vector2f(1600, 80));
        head.setFillColor(sf::Color::Color(247, 251, 250));
        head.setPosition(0.f, 0.f);

        //Font
        if (!roboto.loadFromFile(pathFont+"Roboto-Black.ttf")) std::cout << "False";

        //Eule Pic
        if (!eule.loadFromFile(pathImage+"Eule.PNG")) std::cout << "False";
        eules.setTexture(eule);
        eules.setPosition(sf::Vector2f(900.f, 140.f));
        eules.setScale(sf::Vector2f(0.25f, 0.25f));

        //Pink pic
        if (!pink.loadFromFile(pathImage+ "Pink.PNG")) std::cout << "False";
        pinks.setTexture(pink);
        pinks.setScale(sf::Vector2f(0.35f, 0.35f));
        pinks.setPosition(sf::Vector2f(800.f, 100.f));

        //Orange pic
        if (!orange.loadFromFile(pathImage + "Orange.PNG")) std::cout << "False";
        oranges.setTexture(orange);
        oranges.setScale(sf::Vector2f(0.35f, 0.35f));
        oranges.setPosition(sf::Vector2f(800.f, 100.f));

        //LightVi
        if (!lightvi.loadFromFile(pathImage + "LightVi.PNG")) std::cout << "False";
        lightvis.setTexture(lightvi);
        lightvis.setScale(sf::Vector2f(0.35f, 0.35f));
        lightvis.setPosition(sf::Vector2f(800.f, 100.f));

        //BlueVi
        if (!bluevi.loadFromFile(pathImage + "BlueVi.PNG")) std::cout << "False";
        bluevis.setTexture(bluevi);
        bluevis.setScale(sf::Vector2f(0.35f, 0.35f));
        bluevis.setPosition(sf::Vector2f(800.f, 100.f));

        //VN
        if (!vn.loadFromFile(pathImage + "VN.PNG")) std::cout << "False";
        vns.setTexture(vn);
        vns.setScale(sf::Vector2f(0.11f, 0.11f));
        vns.setPosition(sf::Vector2f(150.f, 200.f));

        //Eng
        if (!eng.loadFromFile(pathImage + "Eng.PNG")) std::cout << "False";
        engs.setTexture(eng);
        engs.setScale(sf::Vector2f(0.11f, 0.11f));
        engs.setPosition(sf::Vector2f(350.f, 200.f));

        //Home
        if (!home.loadFromFile(pathImage + "Home.PNG")) std::cout << "False";
        homes.setTexture(home);
        homes.setScale(sf::Vector2f(0.14f, 0.14f));
        homes.setPosition(sf::Vector2f(20.f, 10.f));

        //Textbox: Word
        textbox1.create(15, sf::Color::White, true);
        textbox1.setFont(roboto);
        textbox1.setPosition({ 920,500 });

        //Textbox: Def
        textbox2.create(15, sf::Color::White, true);
        textbox2.setFont(roboto);
        textbox2.setPosition({ 920,650 });

        //Button
        btn1.create("", { 700.f, 550.f }, sf::Color::Color(255, 255, 255, 80), 20, sf::Color::White);
        btn1.setFont(roboto);
        btn1.setPosition({ 770,320 });

        //
        btnWord.create("", { 70.f, 55.f }, sf::Color::Transparent, 20, sf::Color::White);
        btnWord.setFont(roboto);
        btnWord.setPosition({ 820,460 });
        btnWord.specialBtn({ 820,460 });
        btnWord.setContent("Word");

        //
        btnDef.create("", { 70.f, 55.f }, sf::Color::Transparent, 20, sf::Color::Color(162, 162, 162));
        btnDef.setFont(roboto);
        btnDef.setPosition({ 810,610 });
        btnDef.specialBtn({ 810,610 });
        btnDef.setContent("Defi");
        btnDef.content.setFillColor(sf::Color::Color(162, 162, 162));

        //
        total.create("Total", { 150.f, 150.f }, sf::Color::Color(255, 255, 255, 150), 20, sf::Color::White);
        recent.create("Recent", { 360.f, 325.f }, sf::Color::Color(255, 255, 255, 150), 20, sf::Color::White);
        total.setFont(roboto);
        recent.setFont(roboto);
        total.specialBtn({ 150,360 });
        recent.specialBtn({ 150,540 });

        //Main variables
        checkAllDict(recentword_v, cnt_v, nameDict_v, root);
        total.setContent(std::to_string(cnt_v[0]));
        recent.setContent(recentword_v[0]);

        //vector
        sprite_v = { eules, pinks, oranges, lightvis, bluevis };
        color_v = { sf::Color::Color(77, 171, 135, 255), sf::Color::Color(253, 99, 190, 255), sf::Color::Color(254,144,83,255), sf::Color::Color(153,142,232,255)
    ,sf::Color::Color(96,13,198,255) };
        sprite_lang_v = { engs, vns };
        sprite_tmp = sprite_v[0];
        color_tmp = color_v[0];
        background.setFillColor(color_tmp);
        changeLang(0, sprite_lang_v, lang1, lang2);
    }

    //handle event
    void handleEvent(const sf::Event& event) override {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            setCallHome(true);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            lr++;
            if (lr > 4) lr = 0;
            sprite_tmp = sprite_v[lr];
            color_tmp  = color_v[lr];
            background.setFillColor(color_tmp);
            changeLang(lr, sprite_lang_v, lang1, lang2);
            changeText(btnWord, lr);
            nameDict = nameDict_v[lr];
            total.setContent(std::to_string(cnt_v[lr]));
            recent.setContent(recentword_v[lr]);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            lr--;
            if (lr < 0) lr = 4;
            sprite_tmp = sprite_v[lr];
            color_tmp  = color_v[lr];
            background.setFillColor(color_tmp);
            changeLang(lr, sprite_lang_v, lang1, lang2);
            changeText(btnWord, lr);
            nameDict = nameDict_v[lr];
            total.setContent(std::to_string(cnt_v[lr]));
            recent.setContent(recentword_v[lr]);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            tmp = &textbox2;
            textbox1.setTextColor(sf::Color::Color(162, 162, 162));
            textbox2.setTextColor(sf::Color::White);
            btnWord.content.setFillColor(sf::Color::Color(162, 162, 162));
            btnDef.content.setFillColor(sf::Color::White);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            tmp = &textbox1;
            textbox2.setTextColor(sf::Color::Color(162, 162, 162));
            textbox1.setTextColor(sf::Color::White);
            btnDef.content.setFillColor(sf::Color::Color(162, 162, 162));
            btnWord.content.setFillColor(sf::Color::White);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            inputFile(root, nameDict, textbox1.getText(), textbox2.getText(), cnt_v[lr], recentword_v[lr]);
            total.setContent(std::to_string(cnt_v[lr]));
            recent.setContent(recentword_v[lr]);
        }

        switch (event.type) {
            case sf::Event::TextEntered:
                tmp->typedOn(event);
                break;
        }
    }

    void update() override {}

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override {
        target.draw(background);
        target.draw(head);
        target.draw(sprite_tmp);
        target.draw(lang1);
        target.draw(lang2);
        target.draw(homes);
        textbox1.drawTo(target);
        textbox2.drawTo(target);
        btn1.drawTo(target);
        btnWord.drawTo(target);
        btnDef.drawTo(target);
        total.drawTo(target);
        recent.drawTo(target);
    }
};