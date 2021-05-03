#include "UI.h"

using namespace std;

void UI::updateFlashcard(int id)
{
	int difficulty;
	string front;
	string back;
	cout << "Please enter the new difficulty: ";
	cin >> difficulty;
	cout << endl;
	while (difficulty < 1 || difficulty > 5) {
		cout << "The difficulty value should be between 1 and 5" << endl
			<< "Please enter the new difficulty: ";
		cin >> difficulty;
		cout << endl;
	}
	cout << "Please enter the new front word: ";
	cin >> front;
	cout << endl;
	cout << "Please enter the new back word: ";
	cin >> back;
	cout << endl;
	this->ctrl.CTRLUpdateFlashcard(id, difficulty, front, back);
}

void UI::updateGuessTheMeaning(int id)
{
	int difficulty;
	string foreignWord;
	string options[4];
	int correctOptionsIndex;
	cout << "Please enter the new difficulty: ";
	cin >> difficulty;
	cout << endl;
	while (difficulty < 1 || difficulty > 5) {
		cout << "The difficulty value should be between 1 and 5" << endl
			<< "Please enter the new difficulty: ";
		cin >> difficulty;
		cout << endl;
	}
	cout << "Please enter the new foreign word: ";
	cin >> foreignWord;
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << "Please enter the new option at index " << i << ": ";
		cin >> options[i];
		cout << endl;
	}
	cout << "Please enter the index of the correct option: ";
	cin >> correctOptionsIndex;
	cout << endl;
	while (correctOptionsIndex < 0 || correctOptionsIndex > 3) {
		cout << "The value you entered is not valid..." << endl;
		cout << "Please enter the index of the correct option: ";
		cin >> correctOptionsIndex;
	}
	this->ctrl.CTRLUpdateGuessTheMeaning(id, difficulty, foreignWord, options, correctOptionsIndex);
}

bool UI::isNotValidCommand(int input)
{
	return input < 0 || input > 6;
}

void UI::addExercise()
{
	cout << "What type of exercise do you wish to add?" << endl 
		<< "1. Flashcard" << endl 
		<< "2. Guess the Meaning" << endl 
		<< "Enter your choice: ";
	int type;
	cin >> type;
	cout << endl;
	type--;
	while (type != FLASHCARD && type != GUESS_THE_MEANING) {
		cout << "Please enter a valid input..." << endl
			<< "Enter your choice: ";
		cin >> type;
		cout << endl;
	}
	cout << endl;
	Exercise* exercise = this->readExercise(type);
	this->ctrl.CTRLAddExercise(exercise);
}

void UI::removeExercise(int id)
{
	Exercise* e = this->ctrl.getRepo().getExerciseById(id);
	if (e == nullptr) {
		cout << "The ID you entered is not valid...";
	}
	else {
		this->ctrl.CTRLRemoveExercise(id);
	}
}

void UI::updateExercise(int id)
{
	Exercise* exercise = this->ctrl.getRepo().getExerciseById(id);
	if (exercise == nullptr) {
		cout << "The ID you entered is not valid...";
	}
	else {
		if (typeid(exercise) == typeid(Flashcard*)) {
			this->updateFlashcard(id);
		}
		else {
			this->updateGuessTheMeaning(id);
		}
	}
}

void UI::searchExercise(int id)
{
	int index = this->ctrl.CTRLSearchExercise(id);
	if (index == -1) {
		cout << "There is no exercise with id " << id << endl;
	}
	else {
		cout << "The exercise was found at index " << index << endl;
	}
}

void UI::filterByDifficulty(int difficulty)
{
	ExerciseRepository r{ this->ctrl.CTRLFilterByDifficulty(difficulty) };
	cout << r;
}

void UI::printRepository()
{
	cout << this->ctrl.getRepo();
}

void UI::printMenu()
{
	cout << endl
		<< "1. Add Exercise" << endl
		<< "2. Remove Exercise (by ID)" << endl
		<< "3. Update Exercise (by ID)" << endl
		<< "4. Search for an Exercise (by ID)" << endl
		<< "5. Filter by difficulty" << endl
		<< "6. Print Repository" << endl
		<< "0. Exit" << endl;
}

int UI::readInput()
{
	int input;
	cout << "Please enter a command: ";
	cin >> input;
	cout << endl;
	while (this->isNotValidCommand(input)) {
		cout << "Please enter a valid input: ";
		cin >> input;
		cout << endl;
	}
	return input;
}

Exercise* UI::readExercise(int type)
{
	int id;
	int difficulty;
	string front;
	string back;
	string foreignWord;
	string options[4];
	int correctOptionsIndex;
	Flashcard* f;
	GuessTheMeaning* g;
	switch (type) {
	case FLASHCARD:
		cout << "Please enter the ID: ";
		cin >> id;
		cout << endl;
		while (this->ctrl.CTRLSearchExercise(id) != -1) {
			cout << "An exercise with this ID already exists in the repository..." << endl;
			cout << "Please enter the ID: ";
			cin >> id;
			cout << endl;
		}
		cout << "Please enter the difficulty: ";
		cin >> difficulty;
		cout << endl;
		while (difficulty < 1 || difficulty > 5) {
			cout << "The difficulty value should be between 1 and 5" << endl
				<< "Please enter the difficulty: ";
			cin >> difficulty;
			cout << endl;
		}
		cout << "Please enter the front word: ";
		cin >> front;
		cout << endl;
		cout << "Please enter the back word: ";
		cin >> back;
		cout << endl;
		f = new Flashcard(id, difficulty, front, back);
		return f;
		break;
	case GUESS_THE_MEANING:
		cout << "Please enter the ID: ";
		cin >> id;
		cout << endl;
		while (this->ctrl.CTRLSearchExercise(id) != -1) {
			cout << "An exercise with this ID already exists in the repository..." << endl;
			cout << "Please enter the ID: ";
			cin >> id;
			cout << endl;
		}
		cout << "Please enter the difficulty: ";
		cin >> difficulty;
		cout << endl;
		while (difficulty < 1 || difficulty > 5) {
			cout << "The difficulty value should be between 1 and 5" << endl
				<< "Please enter the difficulty: ";
			cin >> difficulty;
			cout << endl;
		}
		cout << "Please enter the foreign word: ";
		cin >> foreignWord;
		cout << endl;
		for (int i = 0; i < 4; i++) {
			cout << "Please enter the option at index " << i << ": ";
			cin >> options[i];
			cout << endl;
		}
		cout << "Please enter the index of correct option: ";
		cin >> correctOptionsIndex;
		cout << endl;
		while (correctOptionsIndex < 0 || correctOptionsIndex > 3) {
			cout << "The value you entered is not valid..." << endl;
			cout << "Please enter the index of the correct option: ";
			cin >> correctOptionsIndex;
		}
		g = new GuessTheMeaning(id, difficulty, foreignWord, options, correctOptionsIndex);
		return g;
		break;
	default:
		break;
	}
}

void UI::mainLoop()
{
	int difficulty;
	int command;
	int id;
	while (true) {
		this->printMenu();
		command = this->readInput();
		switch (command) {
		case 1:
			this->addExercise();
			break;
		case 2:
			cout << "Please enter the ID of the exercise you wish to remove: ";
			cin >> id;
			cout << endl;
			this->removeExercise(id);
			break;
		case 3:
			cout << "Please enter the ID of the exercise you wish to update: ";
			cin >> id;
			cout << endl;
			this->updateExercise(id);
			break;
		case 4:
			cout << "Please enter the ID of the exercise you wish to search for: ";
			cin >> id;
			cout << endl;
			this->searchExercise(id);
			break;
		case 5:
			cout << "Please enter the difficulty: ";
			cin >> difficulty;
			cout << endl;
			this->filterByDifficulty(difficulty);
			break;
		case 6:
			this->printRepository();
			break;
		case 0:
			goto end;
			break;
		default:
			break;
		}
	}
end:
	cout << "Goodbye!!" << endl;
}
