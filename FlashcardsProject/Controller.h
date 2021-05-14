#pragma once
#include "ExerciseRepository.h"

using namespace std;

class Controller {

private:
	ExerciseRepository repo;
public:
	Controller(ExerciseRepository repo) : repo(repo) {}
	~Controller() {}
	ExerciseRepository getRepo() { return repo; }
	void CTRLAddExercise(Exercise* e);
	bool CTRLRemoveExercise(int id);
	bool CTRLUpdateFlashcard(int id, int difficulty, string front, string back);
	bool CTRLUpdateGuessTheMeaning(int id, int difficulty, string foreignWord, string options[4], int correctOptionIndex);
	int CTRLSearchExercise(int id);
	vector<Exercise*> CTRLFilterByDifficulty(int difficulty);
	void CTRLUndo();
	void CTRLRedo();
};