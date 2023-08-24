#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "..\dataManager\TrieDefinition\TrieDefinition.h"
#include "..\dataManager\TrieWord\TrieWord.h"

class randomSpace : Words {
public:
    std::vector<std::string> listQues;
    std::vector<std::vector<std::string> > listChoice;
    std::vector<int> listAns;
    Words* Dic;
    int ranInt = rand()%29;

    randomSpace() {
        //this->Dic = &root->Dic;
        std::srand(time(0));
    }
    void morespace() {
        std::vector<std::string> v = { "a","a","a","a" };
        listChoice.push_back(v);
    }

    void randomWord() {
        int tmp1 = rand() % Dic->v.size();

        listQues.push_back(Dic->v[tmp1].word);
        std::cout << tmp1 << std::endl;

        int tmp2 = rand() % 4;
        morespace();
        (*(listChoice.end() - 1))[tmp2] = Dic->v[tmp1].definitions[0];
        listAns.push_back(tmp2);

        int cnt = 0;
        while (true) {
            tmp1 = rand() % 4;

            if ((*(listChoice.end() - 1))[tmp1] == "a") {
                (*(listChoice.end() - 1))[tmp1] = Dic->v[rand() % Dic->v.size()].definitions[0];
                cnt++;
            }

            if (cnt == 3) return;
        }
    }

    void clearFile(std::string s) {
        std::ofstream ft(s);
        ft << "";
        ft.close();
    }

    void printAll(std::string s) {
        clearFile(s);
        std::ofstream ft(s);

        for (int i = 0; i < listQues.size(); i++) {
            ft << listQues[i] << '\n';
            for (auto j : listChoice[i]) ft << j << '\t';
            ft << '\n' << listAns[i] << '\n';
        }

        ft.close();
    }

    void readFile(std::string s) {
        std::ifstream fin(s);

        std::string tmp;
        while (!fin.eof()) {
            getline(fin, tmp, '\n');

            if (fin.eof()) {
                fin.close();
                return;
            }

            listQues.push_back(tmp);

            morespace();
            for (int i = 0; i < 4; i++) {
                getline(fin, tmp, '\t');
                (*(listChoice.end() - 1))[i] = tmp;
            }

            getline(fin, tmp, '\n');
            getline(fin, tmp, '\n');
            listAns.push_back(std::stoi(tmp));
        }
    }

    void resetFile() {
        std::vector<std::string> nthQues;
        std::vector<std::vector<std::string>> nthChoice;
        std::vector<int> nthAns;

        listQues = nthQues;
        listChoice = nthChoice;
        listAns    = nthAns;
    }
};
