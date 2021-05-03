#pragma once
#include "Exercise.h"

using namespace std;

class Flashcard : public Exercise {
private:
	string front;
	string back;
public:
	Flashcard() : Exercise(0, 0) { front = ""; back = ""; }
	Flashcard(Flashcard& f) { front = f.front; back = f.back; }
	Flashcard(int id, int dif, string f, string b) : Exercise(id, dif) { front = f; back = b; }
	string getFront();
	void setFront(string newFront);
	string getBack();
	void setBack(string newBack);
protected:
	virtual void print(ostream& out) const;
};