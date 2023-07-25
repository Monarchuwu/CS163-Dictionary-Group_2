#include "function.h"


bool check(std::string t) {
	std::string tmp = "0123456789abcdefghiklmnopqrstuvwyzABCDEFGHIKLMNOPQRSTUVWYZ'-! ";
	for (int i = 0; i < t.length(); i++) {
		if (tmp.find(t[i]) == std::string::npos) return 0;
	}
	return 1;
}

void inputFile(Trie* root, std::string& nameDict, std::string word, std::string def, int& cnt, std::string& recentword) {
	if (word.length() == 0 || def.length() < 1 || !check(word) || !check(def)) return;

	std::vector<std::string> tmp;
	if (root->find(root, word, tmp) && find(tmp.begin(), tmp.end(), def) != tmp.end()) return;

	std::ofstream ft(nameDict, std::fstream::app);
	ft << word << '\t' << def << '\n';
	ft.close();

	cnt++;
	recentword = word;
	root->insert(root, word, def);
}

void outputFile(Trie* root, std::string& nameDict, int& cnt, std::string& recentword) {
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
		root->insert(root, word, def);
		word = "";
		def = "";
	}
	
	fin.close();
}

void changeLang(int i, std::vector<sf::Sprite> v, sf::Sprite& lang1, sf::Sprite& lang2) {
	if (i > 4 || i < 0) i = 0;
	sf::Sprite tmp;
	lang1 = tmp;
	lang2 = tmp;
	if (i == 0) {
		lang1 = v[0];
		lang2 = v[0];
		lang2.setPosition(sf::Vector2f(150.f, 200.f));
		return;
	}
	if (i == 1) {
		lang1 = v[0];
		lang2 = v[1];
		lang1.setPosition(sf::Vector2f(150.f, 200.f));
		lang2.setPosition(sf::Vector2f(350.f, 200.f));
		return;
	}
	if (i == 2) {
		lang1 = v[1];
		lang2 = v[0];
		return;
	}
}

void changeText(Button& btn, int lr) {
	if (lr == 3) btn.content.setString("Emoji");
	else if (lr == 4) btn.content.setString("Slang");
	else btn.content.setString("Word");
}

void checkAllDict(std::vector<std::string>& recentword_v, std::vector<int>& cnt_v, std::vector<std::string>& nameDict_v, Trie* root) {
	for (int i = 0; i < 5; i++) {
		std::string recentword = "";
		int cnt = 0;
		outputFile(root, nameDict_v[i], cnt, recentword);
		recentword_v.push_back(recentword);
		cnt_v.push_back(cnt);
	}
}