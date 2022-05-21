/*
ID: alexlee8
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int checkWord(string word, unordered_map<char, int> letToIndex) {
	int val = 1;
	for (int i = 0; i < word.length(); i++) {
		val = val * letToIndex[word[i]];
	}
	return val;
}

int main() {
	ofstream fout ("ride.out");

	ifstream fin ("ride.in");
	string line;
	vector<string> words;
	while (getline(fin, line)) {
		words.push_back(line);
	}

	string alphabet = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unordered_map<char, int> letToIndex;
	for (int i = 0; i < alphabet.length(); i++) {
		letToIndex.insert({alphabet[i], i});
	}

	int word1val = checkWord(words[0], letToIndex);
	int word2val = checkWord(words[1], letToIndex);

	if (word1val % 47 == word2val % 47) {
		fout << "GO" << endl;
	} else {
		fout << "STAY" << endl;
	}

	return 0;
}
