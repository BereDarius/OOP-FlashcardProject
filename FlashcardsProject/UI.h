#pragma once

#include <iostream>
#include "Controller.h"

enum type {
	FLASHCARD = 0,
	GUESS_THE_MEANING = 1
};

class UI {

private:
	Controller ctrl;
	void updateFlashcard(int id);
	void updateGuessTheMeaning(int id);
	bool isNotValidInput();
	bool isNotValidCommand(int command);
	void addExercise();
	void removeExercise(int id);
	void updateExercise(int id);
	void searchExercise(int id);
	void filterByDifficulty(int difficulty);
	void printRepository();
	void printMenu();
	int readInput();
	Exercise* readExercise(int type);
public:
	UI(Controller c) : ctrl(c) {}
	~UI() {}
	void mainLoop();
};