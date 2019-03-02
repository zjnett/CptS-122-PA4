/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA4
File: DietPlan.h
Description: This program allows for diet and exercise plans to be loaded, viewed, and edited from files.
*/

#pragma once

#include "PA4.h"

class DietPlan {
public:
	// DietPlan Default Constructor
	DietPlan();
	// DietPlan Default Destructor
	~DietPlan();
	// DietPlan Constructor (with parameter fields)
	DietPlan(int goal, std::string name, std::string date);
	// DietPlan Copy Constructor (parameter with reference to old object)
	DietPlan(DietPlan &old);
	// setGoalCalories(), parameter goal integer, return type void.
	// Public interface to set the goal calories of the DietPlan. Mutator.
	void setGoalCalories(int goal);
	// getGoalCalories()
	// Public interface to get the goal calories of the DietPlan. Accessor.
	int getGoalCalories();
	// setPlanName(), parameter string plan, return type void.
	// Public interface to set the name of the DietPlan. Mutator.
	void setPlanName(std::string plan);
	// getPlanName()
	// Public interface to get the name of the DietPlan. Accessor.
	std::string getPlanName();
	// setPlanDate(), parameter string date, return type void.
	// Public interface to set the date of the DietPlan. Mutator.
	void setPlanDate(std::string date);
	// getPlanDate()
	// Public interface to get the date of the DietPlan. Accessor.
	std::string getPlanDate();
	// editGoal(), no parameters and return type void
	// Requests the number of calories to be edited into the current object, then uses member mutator to set goal calories.
	void editGoal(void);
	// toString(), no parameters, return type string
	// Utility function that returns concatenated string of the instance of the DietPlan.
	std::string toString(void);

private:
	// Data members
	int goalCalories;
	std::string planName;
	std::string planDate;
};

// Overloaded stream extraction operator to read DietPlan from file (fstream).
// Parameters reference to fstream lhs (left-hand side), reference to DietPlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator >> (std::fstream &lhs, DietPlan &rhs);
// Overloaded stream insertion operator to write DietPlan to console window.
// Parameters reference to ostream lhs (left-hand side), reference to DietPlan rhs (right-hand side)
// Returns modified lhs.
std::ostream & operator << (std::ostream &lhs, DietPlan &rhs);
// Overloaded stream insertion operator to write DietPlan to dietPlans.txt (file).
// Parameters reference to fstream lhs (left-hand side), reference to DietPlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator << (std::fstream &lhs, DietPlan &rhs);