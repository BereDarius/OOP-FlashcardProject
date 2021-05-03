#include "Flashcard.h"

string Flashcard::getFront()
{
	return front;
}

void Flashcard::setFront(string newFront)
{
	front = newFront;
}

string Flashcard::getBack()
{
	return back;
}

void Flashcard::setBack(string newBack)
{
	back = newBack;
}

void Flashcard::print(ostream& out) const {
	out << "ID: " << this->id << "difficulty: N" << this->difficultyLevel << "; front: " << this->front << "; back: " << this->back << endl;
}