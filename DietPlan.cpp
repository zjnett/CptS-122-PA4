/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA4
File: DietPlan.cpp
Description: This program allows for diet and exercise plans to be loaded, viewed, and edited from files.
*/

#include "PA4.h"
#include "DietPlan.h"

// DietPlan Default Constructor
DietPlan::DietPlan() {
	goalCalories = 0;
	planName = "";
	planDate = "";
}

// DietPlan Default Destructor
DietPlan::~DietPlan() {
	//implicit destructor, destructs when object leaves scope
}

// DietPlan Constructor (with parameter fields)
DietPlan::DietPlan(int goal, std::string name, std::string date) {
	goalCalories = goal;
	planName = name;
	planDate = date;
}

// DietPlan Copy Constructor (parameter with reference to old object)
DietPlan::DietPlan(DietPlan &old) {
	goalCalories = old.getGoalCalories();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}

// setGoalCalories(), parameter goal integer, return type void.
// Public interface to set the goal calories of the DietPlan. Mutator.
void DietPlan::setGoalCalories(int goal) {
	if (goal < 0) {
		goalCalories = 0;
	} else {
		goalCalories = goal;
	}
}

// getGoalCalories()
// Public interface to get the goal calories of the DietPlan. Accessor.
int DietPlan::getGoalCalories() {
	return goalCalories;
}

// setPlanName(), parameter string plan, return type void.
// Public interface to set the name of the DietPlan. Mutator.
void DietPlan::setPlanName(std::string plan) {
	planName = plan;
}

// getPlanName()
// Public interface to get the name of the DietPlan. Accessor.
std::string DietPlan::getPlanName() {
	return planName;
}

// setPlanDate(), parameter string date, return type void.
// Public interface to set the date of the DietPlan. Mutator.
void DietPlan::setPlanDate(std::string date) {
	planDate = date;
}

// getPlanDate()
// Public interface to get the date of the DietPlan. Accessor.
std::string DietPlan::getPlanDate() {
	return planDate;
}

// editGoal(), no parameters and return type void
// Requests the number of calories to be edited into the current object, then uses member mutator to set goal calories.
void DietPlan::editGoal(void) {
	system("cls");
	int newGoal = 0;
	std::cout << "How many calories is your new goal?: ";
	std::cin >> newGoal;
	setGoalCalories(newGoal);
}

// toString(), no parameters, return type string
// Utility function that returns concatenated string of the instance of the DietPlan.
std::string DietPlan::toString(void) {
	return "Diet Plan " + planName + " for " + planDate + ": Goal: " + std::to_string(goalCalories) + " calories";
}

// Overloaded stream extraction operator to read DietPlan from file (fstream).
// Parameters reference to fstream lhs (left-hand side), reference to DietPlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator >> (std::fstream &lhs, DietPlan &rhs) {
	std::string name;
	std::getline(lhs, name);
	std::string strCalories;
	std::getline(lhs, strCalories);
	int calories = stoi(strCalories);
	std::string date;
	std::getline(lhs, date);
	std::string newline;
	std::getline(lhs, newline);
	rhs.setPlanName(name);
	rhs.setGoalCalories(calories);
	rhs.setPlanDate(date);
	return lhs;
}

// Overloaded stream insertion operator to write DietPlan to console window.
// Parameters reference to ostream lhs (left-hand side), reference to DietPlan rhs (right-hand side)
// Returns modified lhs.
std::ostream & operator << (std::ostream &lhs, DietPlan &rhs) {
	lhs << "Diet Plan " << rhs.getPlanName() << " for " << rhs.getPlanDate() << ": Goal: " << rhs.getGoalCalories() << " calories";
	return lhs;
}

// Overloaded stream insertion operator to write DietPlan to dietPlans.txt (file).
// Parameters reference to fstream lhs (left-hand side), reference to DietPlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator << (std::fstream &lhs, DietPlan &rhs) {
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getGoalCalories() << std::endl;
	lhs << rhs.getPlanDate() << std::endl;
	lhs << "\n";
	return lhs;
}
