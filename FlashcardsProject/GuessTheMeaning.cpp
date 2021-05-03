#include "GuessTheMeaning.h"

GuessTheMeaning::GuessTheMeaning(GuessTheMeaning& g)
{
	this->id = g.id;
	this->difficultyLevel = g.difficultyLevel;
	this->foreignWord = g.foreignWord;
	for (int i = 0; i < 4; i++) {
		this->options[i] = g.options[i];
	}
	this->correctOptionIndex = g.correctOptionIndex;
}

string* GuessTheMeaning::getOptions()
{
	return options;
}

void GuessTheMeaning::setOptions(string opt[4])
{
	for (int i = 0; i < 4; i++) {
		options[i] = opt[i];
	}
}

int GuessTheMeaning::getCorrectOptionIndex()
{
	return correctOptionIndex;
}

void GuessTheMeaning::setCorrectOptionIndex(int index)
{
	correctOptionIndex = index;
}

void GuessTheMeaning::print(ostream& out) const
{
	out << "difficulty: N" << this->difficultyLevel << "; foreign word: " << this->foreignWord << "; options: [" <<
		this->options[0] << ", " << this->options[1] << ", " << this->options[2] << ", " << this->options[3] << "]; " <<
		"correct answer: " << this->options[this->correctOptionIndex] << endl;
}