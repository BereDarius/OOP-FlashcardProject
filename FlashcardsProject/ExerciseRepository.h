#pragma once
#include "Flashcard.h"
#include "GuessTheMeaning.h"
#include <vector>
#include <stack>
#include <ostream>
#include <algorithm>
#include <utility>

using namespace std;

enum operation {
	ADD = 0,
	REMOVE = 1,
	UPDATE_FLASHCARD = 2,
	UPDATE_GUESS_THE_MEANING = 3
};

class ExerciseRepository {
private:
	vector<Exercise*> exercises;
	stack<pair<int, Exercise*>> undoStack;
	stack<pair<int, Exercise*>> redoStack;
	void printExercise(ostream& os, Exercise* e) const;
public:
	ExerciseRepository(vector<Exercise*> e) : exercises(e) {}
	~ExerciseRepository() {}
	vector<Exercise*> getExercises();
	void addExercise(Exercise* e);
	bool removeExercise(int id);
	bool updateFlashcard(int id, int difficulty, string front, string back);
	bool updateGuessTheMeaning(int id, int difficulty, string foreignWord, string options[4], int correctOptionIndex);
	int searchExercise(int id);
	Exercise* getExerciseById(int id);
	vector<Exercise*> filterByDifficulty(int difficulty);
	friend ostream& operator<<(ostream& os, const ExerciseRepository& e);
	void undo();
	void redo();
};