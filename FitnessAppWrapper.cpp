#include "PA4.h"
#include "FitnessAppWrapper.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

FitnessAppWrapper::FitnessAppWrapper() { }

FitnessAppWrapper::~FitnessAppWrapper() { }

void FitnessAppWrapper::runApp(void) {
	DietPlan dietPlanList[7] = {};
	ExercisePlan exercisePlanList[7] = {};
	bool isRunning = true;

	fstream fsDiet;
	fsDiet.open("dietPlans.txt");
	fstream fsExercise;
	fsExercise.open("exercisePlans.txt");

	while (isRunning) {
		//ANSI Escape sequence for clearing screen
		cout << "\033[2J\033[1;1H";
		displayMenu();
		int choice = 0;
		choice = getInt();
		switch (choice) {
		case 1:
			//Load weekly diet plan
			loadWeeklyPlan(fsDiet, dietPlanList);
			cout << "Weekly diet plan loaded!" << endl;
			pauseForInput();
			break;
		case 2:
			//Load weekly exercise plan
			loadWeeklyPlan(fsExercise, exercisePlanList);
			cout << "Weekly exercise plan loaded!" << endl;
			pauseForInput();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			isRunning = false;
			break;
		}
	}
}

int FitnessAppWrapper::getInt(void) {
	int num = 0;
	cin >> num;
	return num;
}

void FitnessAppWrapper::pauseForInput(void) {
	cout << "Press a key and enter to continue..." << endl;
	char temp = '\0';
	cin >> temp;
	system("pause");
}

void FitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, ExercisePlan &plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(std::fstream &fileStream, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(std::fstream &fileStream, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan &plan) {
	cout << plan << endl;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan &plan) {
	cout << plan << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayMenu(void) {
	cout << "\tFITNESS APPLICATION" << endl;
	cout << "1.    Load weekly diet plan from file." << endl;
	cout << "2.    Load weekly exercise plan from file." << endl;
	cout << "3.    Store weekly diet plan to file." << endl;
	cout << "4.    Store weekly exercise plan to file." << endl;
	cout << "5.    Display weekly diet plan to screen." << endl;
	cout << "6.    Display weekly exercise plan to screen." << endl;
	cout << "7.    Edit daily diet plan." << endl;
	cout << "8.    Edit daily exercise plan." << endl;
	cout << "9.    Exit." << endl;
}
