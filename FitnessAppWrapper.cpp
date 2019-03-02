/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA4
File: FitnessAppWrapper.cpp
Description: This program allows for diet and exercise plans to be loaded, viewed, and edited from files.
*/

#include "PA4.h"
#include "FitnessAppWrapper.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

// FitnessAppWrapper Default Constructor.
FitnessAppWrapper::FitnessAppWrapper() { }

// FitnessAppWrapper Default Destructor.
FitnessAppWrapper::~FitnessAppWrapper() { }

// runApp()
// Wrapper function that handles main execution of the program. Includes instantiation of object lists.
void FitnessAppWrapper::runApp(void) {
	DietPlan dietPlanList[7] = {};
	ExercisePlan exercisePlanList[7] = {};
	bool isRunning = true;

	bool dietLoaded = false, exerciseLoaded = false;

	fstream fsDiet;
	fstream fsExercise;

	while (isRunning) {
		system("cls");
		displayMenu();
		int choice = 0;
		choice = getInt();
		switch (choice) {
		case 1:
			//Load weekly diet plan
			fsDiet.open("dietPlans.txt");
			if (fsDiet.is_open()) {
				loadWeeklyPlan(fsDiet, dietPlanList);
				dietLoaded = true;
				cout << "Weekly diet plan loaded!" << endl;
				fsDiet.close();
			}
			else
			{
				cout << "Error opening dietPlans.txt!" << endl;
			}
			pauseForInput();
			break;
		case 2:
			//Load weekly exercise plan
			fsExercise.open("exercisePlans.txt");
			if (fsExercise.is_open()) {
				loadWeeklyPlan(fsExercise, exercisePlanList);
				exerciseLoaded = true;
				cout << "Weekly exercise plan loaded!" << endl;
				fsExercise.close();
			}
			else
			{
				cout << "Error opening exercisePlans.txt!" << endl;
			}
			pauseForInput();
			break;
		case 3:
			//Store weekly diet plan to file.
			fsDiet.open("dietPlans.txt");
			if (fsDiet.is_open()) {
				writeWeeklyPlanToFile(fsDiet, dietPlanList);
				cout << "Plan written to dietPlans.txt!" << endl;
				fsDiet.close();
			}
			else
			{
				cout << "Error opening dietPlans.txt!" << endl;
			}
			pauseForInput();
			break;
		case 4:
			//Store weekly exercise plan to file.
			fsExercise.open("exercisePlans.txt");
			if (fsExercise.is_open()) {
				writeWeeklyPlanToFile(fsExercise, exercisePlanList);
				cout << "Plan written to exercisePlans.txt!" << endl;
				fsExercise.close();
			}
			else
			{
				cout << "Error opening exercisePlans.txt!" << endl;
			}
			pauseForInput();
			break;
		case 5:
			//Display weekly diet plan to screen.
			if (dietLoaded) {
				displayWeeklyPlan(dietPlanList);
			}
			else
			{
				cout << "No diet plan has been loaded!" << endl;
			}
			pauseForInput();
			break;
		case 6:
			//Display weekly exercise plan to screen.
			if (exerciseLoaded) {
				displayWeeklyPlan(exercisePlanList);
			}
			else
			{
				cout << "No exercise plan has been loaded!" << endl;
			}
			pauseForInput();
			break;
		case 7:
			//Edit daily diet plan.
			if (dietLoaded) {
				int planNumber = chooseDailyPlanFromWeekly(dietPlanList);
				dietPlanList[planNumber].editGoal();
				displayDailyPlan(dietPlanList[planNumber]);
			}
			else 
			{
				cout << "Cannot edit plan -- no diet plan has been loaded!" << endl;
			}
			pauseForInput();
			break;
		case 8:
			//Edit daily exercise plan.
			if (exerciseLoaded) {
				int planNumber = chooseDailyPlanFromWeekly(exercisePlanList);
				exercisePlanList[planNumber].editGoal();
				displayDailyPlan(exercisePlanList[planNumber]);
			}
			else
			{
				cout << "Cannot edit plan -- no exercise plan has been loaded!" << endl;
			}
			pauseForInput();
			break;
		case 9:
			//Exit
			if (dietLoaded) {
				fsDiet.open("dietPlans.txt");
				writeWeeklyPlanToFile(fsDiet, dietPlanList);
				fsExercise.close();
			}
				
			if (exerciseLoaded) {
				fsExercise.open("exercisePlans.txt");
				writeWeeklyPlanToFile(fsExercise, exercisePlanList);
				fsExercise.close();
			}


			//Close files if they are open (failsafe)
			if (fsExercise.is_open())
				fsExercise.close();
			if (fsDiet.is_open())
				fsDiet.close();
			//Set main program loop to false to break execution
			isRunning = false;
			break;
		}
	}
}

// getInt(), no parameters, return type integer
// Helper function that reads an integer from std::cin and returns it.
int FitnessAppWrapper::getInt(void) {
	int num = 0;
	cin >> num;
	return num;
}

// pauseForInput(), no parameters, no return
// Helper function mostly implemented for cross-platform consistency for "press any key to continue" prompts.
void FitnessAppWrapper::pauseForInput(void) {
	//cout << "Press a key and enter to continue..." << endl;
	//char temp = '\0';
	//cin >> temp;
	system("pause");
}

// loadDailyPlan(), return void, parameters reference to filestream and reference to DietPlan
// Uses overloaded operator to load a single plan from filestream into a referenced object
void FitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
}

// loadDailyPlan() (overloaded), return void, parameters reference to filestream and reference to ExercisePlan
// Uses overloaded operator to load a single plan from filestream into a referenced object
void FitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, ExercisePlan &plan) {
	fileStream >> plan;
}

// loadWeeklyPlan(), return void, parameters reference to filestream and array of DietPlans
// Calls loadDailyPlan() 7 times for each day of the week.
void FitnessAppWrapper::loadWeeklyPlan(std::fstream &fileStream, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

// loadWeeklyPlan() (overloaded), return void, parameters reference to filestream and array of ExercisePlans
// Calls loadDailyPlan() 7 times for each day of the week.
void FitnessAppWrapper::loadWeeklyPlan(std::fstream &fileStream, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

// displayDailyPlan(), return void, parameters reference to DietPlan
// Uses overloaded operators to display a single DietPlan.
void FitnessAppWrapper::displayDailyPlan(DietPlan &plan) {
	cout << plan << endl;
}

// displayDailyPlan() (overloaded), return void, parameters reference to ExercisePlan
// Uses overloaded operators to display a single ExercisePlan.
void FitnessAppWrapper::displayDailyPlan(ExercisePlan &plan) {
	cout << plan << endl;
}

// displayWeeklyPlan(), return void, parameters reference array of DietPlans
// Calls displayDailyPlan() 7 times for each day of the week.
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": ";
		displayDailyPlan(weeklyPlan[i]);
	}
}

// displayWeeklyPlan() (overloaded), return void, parameters reference array of ExercisePlans
// Calls displayDailyPlan() 7 times for each day of the week.
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": ";
		displayDailyPlan(weeklyPlan[i]);
	}
}

// writeDailyPlanToFile(), return void, parameters reference filestream and reference to DietPlan object.
// Uses overloaded operator to write a single plan to file.
void FitnessAppWrapper::writeDailyPlanToFile(std::fstream &outfile, DietPlan &plan) {
	outfile << plan;
}

// writeDailyPlanToFile() (overloaded), return void, parameters reference filestream and reference to ExercisePlan object.
// Uses overloaded operator to write a single plan to file.
void FitnessAppWrapper::writeDailyPlanToFile(std::fstream &outfile, ExercisePlan &plan) {
	outfile << plan;
}

// writeWeeklyPlanToFile(), return void, parameters reference to filestream and reference to array of DietPlans
// Calls writeDailyPlanToFile() 7 times for each day of the week.
void FitnessAppWrapper::writeWeeklyPlanToFile(std::fstream &outfile, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		writeDailyPlanToFile(outfile, weeklyPlan[i]);
	}
}

// writeWeeklyPlanToFile() (overloaded), return void, parameters reference to filestream and reference to array of ExercisePlans
// Calls writeDailyPlanToFile() 7 times for each day of the week.
void FitnessAppWrapper::writeWeeklyPlanToFile(std::fstream &outfile, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		writeDailyPlanToFile(outfile, weeklyPlan[i]);
	}
}

// chooseDailyPlanFromWeekly(), return type integer, parameter array of DietPlans
// Helper function for editing, returns user choice of plan they'd like to edit.
int FitnessAppWrapper::chooseDailyPlanFromWeekly(DietPlan weeklyPlan[]) {
	bool choosing = true;
	int choice = 0;
	while (choosing) {
		system("cls");
		displayWeeklyPlan(weeklyPlan);
		cout << "Which plan would you like to modify? (1-7): ";
		cin >> choice;
		if (choice > 0 && choice < 8) {
			choosing = false;
		}
	}
	return choice - 1;
}

// chooseDailyPlanFromWeekly() (overloaded), return type integer, parameter array of ExercisePlans
// Helper function for editing, returns user choice of plan they'd like to edit.
int FitnessAppWrapper::chooseDailyPlanFromWeekly(ExercisePlan weeklyPlan[]) {
	bool choosing = true;
	int choice = 0;
	while (choosing) {
		system("cls");
		displayWeeklyPlan(weeklyPlan);
		cout << "Which plan would you like to modify? (1-7): ";
		cin >> choice;
		if (choice > 0 && choice < 8) {
			choosing = false;
		}
	}
	return choice - 1;
}

// displayMenu()
// Displays the application menu for navigation using std::cout and std::endl.
void FitnessAppWrapper::displayMenu(void) {
	cout << "\t\tbFIT WIN32 FITNESS APPLICATION" << endl;
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
