#pragma once
#include "Flashcard.h"
#include "GuessTheMeaning.h"
#include <vector>
#include <ostream>
#include <algorithm>

using namespace std;

class ExerciseRepository {
private:
	vector<Exercise*> exercises;

	void printExercise(ostream& os, Exercise* e) const;

public:
	ExerciseRepository() {}
	~ExerciseRepository() {}
	vector<Exercise*> getExercises();
	void addExercise(Exercise* e);
	bool removeExercise(int id);
	bool updateFlashcard(int id, int difficulty, string front, string back);
	bool updateGuessTheMeaning(int id, int difficulty, string foreignWord, string options[4], int correctOptionIndex);
	int searchExercise(int id);
	vector<Exercise*> filterByDifficulty(int difficulty);
	friend ostream& operator<<(ostream& os, const ExerciseRepository& e);
};