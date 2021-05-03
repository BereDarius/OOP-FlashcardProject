#include "Flashcard.h"
#include "GuessTheMeaning.h"
#include "UI.h"
#include <iostream>

int main() {
	vector<Exercise*> vect;

	ExerciseRepository repo{ vect };

	Controller c{ repo };

	UI ui{ c };

	ui.mainLoop();

	return 0;
}