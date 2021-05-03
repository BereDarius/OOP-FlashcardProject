#include "Flashcard.h"
#include "GuessTheMeaning.h"
#include "Controller.h"
#include <iostream>

int main() {

	string options[4] = { "I", "You", "He", "She" };

	GuessTheMeaning* g = new GuessTheMeaning(1, 1, "watashi", options, 0);

	Flashcard* f = new Flashcard(2, 2, "kaban", "bag");

	ExerciseRepository repo;

	repo.addExercise(g);
	repo.addExercise(f);

	Controller c{ repo };

	return 0;
}