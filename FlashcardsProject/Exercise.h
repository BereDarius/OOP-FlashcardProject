#pragma once

#include <string>
#include <ostream>

using namespace std;

class Exercise {
protected:
	int id;
	int difficultyLevel;
public:
	Exercise() { id = 0; difficultyLevel = 0; }
	Exercise(int id, int dif) : id(id), difficultyLevel(dif) {}
	virtual ~Exercise() {}
	int getId() { return id; }
	void setId(int newId) { id = newId; }
	int getDifficultyLevel() { return difficultyLevel; }
	void setDifficultyLevel(int newDif) { difficultyLevel = newDif; }
	virtual void print(ostream& out) const {}
};