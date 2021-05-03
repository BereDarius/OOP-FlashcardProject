#pragma once

#include "Exercise.h"

using namespace std;

class GuessTheMeaning : public Exercise {
private:
	string foreignWord;
	string options[4];
	int correctOptionIndex;
public:
	GuessTheMeaning() : Exercise(0, 0) {
		foreignWord = "";
		for (int i = 0; i < 4; i++) {
			options[i] = "";
		}
		correctOptionIndex = -1;
	}
	GuessTheMeaning(GuessTheMeaning& g);
	GuessTheMeaning(int id, int dif, string word, string opt[4], int index) : Exercise(id, dif) {
		foreignWord = word;
		for (int i = 0; i < 4; i++) {
			options[i] = opt[i];
		}
		correctOptionIndex = index;
	}
	~GuessTheMeaning() = default;
	string getForeignWord() { return foreignWord; }
	void setForeignWord(string word) { foreignWord = word; }
	string* getOptions();
	void setOptions(string opt[4]);
	int getCorrectOptionIndex();
	void setCorrectOptionIndex(int index);
protected:
	virtual void print(ostream& out) const;
};