/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA4
File: ExercisePlan.cpp
Description: This program allows for diet and exercise plans to be loaded, viewed, and edited from files.
*/

#include "PA4.h"
#include "ExercisePlan.h"

// ExercisePlan Default Constructor
ExercisePlan::ExercisePlan() {
	goalSteps = 0;
	planName = "";
	planDate = "";
}

// ExercisePlan Constructor (with parameter fields)
ExercisePlan::ExercisePlan(int steps, std::string name, std::string date) {
	goalSteps = steps;
	planName = name;
	planDate = date;
}

// ExercisePlan Copy Constructor (parameter with reference to old object)
ExercisePlan::ExercisePlan(ExercisePlan &old) {
	goalSteps = old.getGoalSteps();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}

// ExercisePlan Default Destructor 
ExercisePlan::~ExercisePlan() {
	//implicit destructor, destructs when object leaves scope
}

// setGoalSteps(), parameter goal integer, return type void.
// Public interface to set the goal steps of the ExercisePlan. Mutator.
void ExercisePlan::setGoalSteps(int steps) {
	if (steps < 0) {
		goalSteps = 0;
	} else {
		goalSteps = steps;
	}
}

// getGoalSteps()
// Public interface to get the goal steps of the ExercisePlan. Accessor.
int ExercisePlan::getGoalSteps() {
	return goalSteps;
}

// setPlanName(), parameter string plan, return type void.
// Public interface to set the name of the ExercisePlan. Mutator.
void ExercisePlan::setPlanName(std::string plan) {
	planName = plan;
}

// getPlanName()
// Public interface to get the name of the ExercisePlan. Accessor.
std::string ExercisePlan::getPlanName() {
	return planName;
}

// setPlanDate(), parameter string date, return type void.
// Public interface to set the date of the ExercisePlan. Mutator.
void ExercisePlan::setPlanDate(std::string date) {
	planDate = date;
}

// getPlanDate()
// Public interface to get the date of the ExercisePlan. Accessor.
std::string ExercisePlan::getPlanDate() {
	return planDate;
}

// editGoal(), no parameters and return type void
// Requests the number of steps to be edited into the current object, then uses member mutator to set goal steps.
void ExercisePlan::editGoal(void) {
	system("cls");
	int newGoal = 0;
	std::cout << "How many steps is your new goal?: ";
	std::cin >> newGoal;
	setGoalSteps(newGoal);
}

// toString(), no parameters, return type string
// Utility function that returns concatenated string of the instance of the ExercisePlan.
std::string ExercisePlan::toString(void) {
	return "Exercise Plan " + planName + " for " + planDate + ": Goal: " + std::to_string(goalSteps) + " steps";
}

// Overloaded stream extraction operator to read ExercisePlan from file (fstream).
// Parameters reference to fstream lhs (left-hand side), reference to ExercisePlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs) {
	std::string name;
	std::getline(lhs, name);
	std::string strSteps;
	std::getline(lhs, strSteps);
	int steps = stoi(strSteps);
	std::string date;
	std::getline(lhs, date);
	std::string newline;
	std::getline(lhs, newline);
	rhs.setPlanName(name);
	rhs.setGoalSteps(steps);
	rhs.setPlanDate(date);
	return lhs;
}

// Overloaded stream insertion operator to write ExercisePlan to console window.
// Parameters reference to ostream lhs (left-hand side), reference to ExercisePlan rhs (right-hand side)
// Returns modified lhs.
std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs) {
	lhs << "Exercise Plan " << rhs.getPlanName() << " for " << rhs.getPlanDate() << ": Goal: " << rhs.getGoalSteps() << " steps";
	return lhs;
}

// Overloaded stream insertion operator to write ExercisePlan to exercisePlans.txt (file).
// Parameters reference to fstream lhs (left-hand side), reference to ExercisePlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator << (std::fstream &lhs, ExercisePlan &rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getGoalSteps() << std::endl;
	lhs << rhs.getPlanDate() << std::endl;
	lhs << "\n";
	return lhs;
}