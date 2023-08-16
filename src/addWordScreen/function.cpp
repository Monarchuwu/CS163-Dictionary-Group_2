#include "function.h"

bool check(std::string t) {
	std::string tmp = "0123456789abcdefghiklmnopqrstuvwyzABCDEFGHIKLMNOPQRSTUVWYZ'-! ";
	for (int i = 0; i < t.length(); i++) {
		if (tmp.find(t[i]) == std::string::npos) return 0;
	}
	return 1;
}

bool inputFile(std::string& nameDict, std::string word, std::string def, int& cnt, std::string& recentword) {
	if (word.length() == 0 || def.length() < 1 || !check(word) || !check(def)) return 0;

	std::ofstream ft(nameDict, std::fstream::app);
	ft << word << '\t' << def << '\n';
	ft.close();

	cnt++;
	recentword = word;
	return 1;
}

void outputFile(std::string& nameDict, int& cnt, std::string& recentword) {
	std::ifstream fin(nameDict);
	std::string word = "";
	std::string def = "";
	std::string tmp;

	while (!fin.eof()) {
		getline(fin, word, '\t');
		if (fin.eof()) return;
		getline(fin, def, '\n');

		cnt++;
		recentword = word; 
		word = "";
		def = "";
	}
	
	fin.close();
}

void changeLang(int dataSet, std::vector<sf::Sprite> v, sf::Sprite& lang1, sf::Sprite& lang2) {
	sf::Sprite tmp;
	lang1 = tmp;
	lang2 = tmp;
	if (dataSet == 0) {
		lang1 = v[0];
		lang2 = v[0];
		lang2.setPosition(sf::Vector2f(150.f, 200.f));
		return;
	}
	if (dataSet == 1) {
		lang1 = v[0];
		lang2 = v[1];
		lang1.setPosition(sf::Vector2f(150.f, 200.f));
		lang2.setPosition(sf::Vector2f(350.f, 200.f));
		return;
	}
	if (dataSet == 2) {
		lang1 = v[1];
		lang2 = v[0];
		return;
	}
}

void changeText(Button& btn, int dataSet) {
	if (dataSet == 3) btn.content.setString("Emoji");
	else if (dataSet == 4) btn.content.setString("Slang");
	else btn.content.setString("Word");
}

void checkAllDict(std::vector<std::string>& recentword_v, std::vector<int>& cnt_v, std::vector<std::string>& nameDict_v) {
	for (int i = 0; i < 5; i++) {
		std::string recentword = "";
		int cnt = 0;
		outputFile(nameDict_v[i], cnt, recentword);
		recentword_v.push_back(recentword);
		cnt_v.push_back(cnt);
	}
}