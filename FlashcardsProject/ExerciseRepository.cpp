#include "ExerciseRepository.h"

void ExerciseRepository::printExercise(ostream& os, Exercise* e) const
{
	e->print(os);
}

vector<Exercise*> ExerciseRepository::getExercises()
{
	return this->exercises;
}

void ExerciseRepository::addExercise(Exercise* e)
{
	this->exercises.push_back(e);
}

bool ExerciseRepository::removeExercise(int id)
{
	int index = this->searchExercise(id);
	if (index == -1) {
		return false;
	}
	this->exercises.erase(this->exercises.begin() + index);
	return true;
}

bool ExerciseRepository::updateFlashcard(int id, int difficulty, string front, string back)
{
	int index = this->searchExercise(id);
	if (index == -1) {
		return false;
	}
	Flashcard* f = new Flashcard(id ,difficulty, front, back);
	this->exercises.at(index) = f;
	return true;
}

bool ExerciseRepository::updateGuessTheMeaning(int id, int difficulty, string foreignWord, string options[4], int correctOptionIndex)
{
	int index = this->searchExercise(id);
	if (index == -1) {
		return false;
	}
	GuessTheMeaning* g = new GuessTheMeaning(id, difficulty, foreignWord, options, correctOptionIndex);
	this->exercises.at(index) = g;
	return true;
}

int ExerciseRepository::searchExercise(int id)
{
	int index = 0;
	for (Exercise* exercise : this->exercises) {
		if (exercise->getId() == id) {
			return index;
		}
		index++;
	}
	return -1;
}

Exercise* ExerciseRepository::getExerciseById(int id)
{
	for (Exercise* exercise : this->exercises) {
		if (exercise->getId() == id) {
			return exercise;
		}
	}
	return nullptr;
}

vector<Exercise*> ExerciseRepository::filterByDifficulty(int difficulty)
{
	vector<Exercise*> result;
	copy_if(this->exercises.begin(), this->exercises.end(), back_inserter(result), [difficulty](Exercise* e) { return e->getDifficultyLevel() == difficulty; });
	return result;
}

ostream& operator<<(ostream& os, const ExerciseRepository& e)
{
	int index = 0;
	for (Exercise* exercise : e.exercises) {
		os << index << ": ";
		e.printExercise(os, exercise);
		index++;
	}
	return os;
}
