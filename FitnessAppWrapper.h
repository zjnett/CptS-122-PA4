/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA4
File: FitnessAppWrapper.h
Description: This program allows for diet and exercise plans to be loaded, viewed, and edited from files.
*/

#pragma once

#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper {
public:
	// FitnessAppWrapper Default Constructor.
	FitnessAppWrapper();
	// FitnessAppWrapper Default Destructor.
	~FitnessAppWrapper();
	// runApp()
	// Wrapper function that handles main execution of the program. Includes instantiation of object lists.
	void runApp(void);
	// getInt(), no parameters, return type integer
	// Helper function that reads an integer from std::cin and returns it.
	int getInt(void);
	// pauseForInput(), no parameters, no return
	// Helper function mostly implemented for cross-platform consistency for "press any key to continue" prompts.
	void pauseForInput(void);
	// loadDailyPlan(), return void, parameters reference to filestream and reference to DietPlan
	// Uses overloaded operator to load a single plan from filestream into a referenced object
	void loadDailyPlan(std::fstream &fileStream, DietPlan &plan);
	// loadDailyPlan() (overloaded), return void, parameters reference to filestream and reference to ExercisePlan
	// Uses overloaded operator to load a single plan from filestream into a referenced object
	void loadDailyPlan(std::fstream &fileStream, ExercisePlan &plan);
	// loadWeeklyPlan(), return void, parameters reference to filestream and array of DietPlans
	// Calls loadDailyPlan() 7 times for each day of the week.
	void loadWeeklyPlan(std::fstream &fileStream, DietPlan weeklyPlan[]);
	// loadWeeklyPlan() (overloaded), return void, parameters reference to filestream and array of ExercisePlans
	// Calls loadDailyPlan() 7 times for each day of the week.
	void loadWeeklyPlan(std::fstream &fileStream, ExercisePlan weeklyPlan[]);
	// displayDailyPlan(), return void, parameters reference to DietPlan
	// Uses overloaded operators to display a single DietPlan.
	void displayDailyPlan(DietPlan &plan);
	// displayDailyPlan() (overloaded), return void, parameters reference to ExercisePlan
	// Uses overloaded operators to display a single ExercisePlan.
	void displayDailyPlan(ExercisePlan &plan);
	// displayWeeklyPlan(), return void, parameters reference array of DietPlans
	// Calls displayDailyPlan() 7 times for each day of the week.
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	// displayWeeklyPlan() (overloaded), return void, parameters reference array of ExercisePlans
	// Calls displayDailyPlan() 7 times for each day of the week.
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
	// writeDailyPlanToFile(), return void, parameters reference filestream and reference to DietPlan object.
	// Uses overloaded operator to write a single plan to file.
	void writeDailyPlanToFile(std::fstream &outfile, DietPlan &plan);
	// writeDailyPlanToFile() (overloaded), return void, parameters reference filestream and reference to ExercisePlan object.
	// Uses overloaded operator to write a single plan to file.
	void writeDailyPlanToFile(std::fstream &outfile, ExercisePlan &plan);
	// writeWeeklyPlanToFile(), return void, parameters reference to filestream and reference to array of DietPlans
	// Calls writeDailyPlanToFile() 7 times for each day of the week.
	void writeWeeklyPlanToFile(std::fstream &outfile, DietPlan weeklyPlan[]);
	// writeWeeklyPlanToFile() (overloaded), return void, parameters reference to filestream and reference to array of ExercisePlans
	// Calls writeDailyPlanToFile() 7 times for each day of the week.
	void writeWeeklyPlanToFile(std::fstream &outfile, ExercisePlan weeklyPlan[]);
	// chooseDailyPlanFromWeekly(), return type integer, parameter array of DietPlans
	// Helper function for editing, returns user choice of plan they'd like to edit.
	int chooseDailyPlanFromWeekly(DietPlan weeklyPlan[]);
	// chooseDailyPlanFromWeekly() (overloaded), return type integer, parameter array of ExercisePlans
	// Helper function for editing, returns user choice of plan they'd like to edit.
	int chooseDailyPlanFromWeekly(ExercisePlan weeklyPlan[]);
	// displayMenu()
	// Displays the application menu for navigation using std::cout and std::endl.
	void displayMenu(void);

private:
	//No private data members.
};
