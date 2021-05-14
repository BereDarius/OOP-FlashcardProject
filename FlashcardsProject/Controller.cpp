#include "Controller.h"

void Controller::CTRLAddExercise(Exercise* e)
{
	this->repo.addExercise(e);
}

bool Controller::CTRLRemoveExercise(int id)
{
	return this->repo.removeExercise(id);
}

bool Controller::CTRLUpdateFlashcard(int id, int difficulty, string front, string back)
{
	return repo.updateFlashcard(id, difficulty, front, back);
}

bool Controller::CTRLUpdateGuessTheMeaning(int id, int difficulty, string foreignWord, string options[4], int correctOptionIndex)
{
	return this->repo.updateGuessTheMeaning(id, difficulty, foreignWord, options, correctOptionIndex);
}

int Controller::CTRLSearchExercise(int id)
{
	return this->repo.searchExercise(id);
}

vector<Exercise*> Controller::CTRLFilterByDifficulty(int difficulty)
{
	return this->repo.filterByDifficulty(difficulty);
}

void Controller::CTRLUndo()
{
	this->repo.undo();
}

void Controller::CTRLRedo()
{
	this->repo.redo();
}
