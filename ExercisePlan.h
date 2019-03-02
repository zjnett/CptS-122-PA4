/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA4
File: ExercisePlan.h
Description: This program allows for diet and exercise plans to be loaded, viewed, and edited from files.
*/

#pragma once

#include "PA4.h"

class ExercisePlan {
public:
	// ExercisePlan Default Constructor
	ExercisePlan();
	// ExercisePlan Constructor (with parameter fields)
	ExercisePlan(int steps, std::string name, std::string date);
	// ExercisePlan Copy Constructor (parameter with reference to old object)
	ExercisePlan(ExercisePlan &old);
	// ExercisePlan Default Destructor 
	~ExercisePlan();
	// setGoalSteps(), parameter goal integer, return type void.
	// Public interface to set the goal steps of the ExercisePlan. Mutator.
	void setGoalSteps(int steps);
	// getGoalSteps()
	// Public interface to get the goal steps of the ExercisePlan. Accessor.
	int getGoalSteps();
	// setPlanName(), parameter string plan, return type void.
	// Public interface to set the name of the ExercisePlan. Mutator.
	void setPlanName(std::string plan);
	// getPlanName()
	// Public interface to get the name of the ExercisePlan. Accessor.
	std::string getPlanName();
	// setPlanDate(), parameter string date, return type void.
	// Public interface to set the date of the ExercisePlan. Mutator.
	void setPlanDate(std::string date);
	// getPlanDate()
	// Public interface to get the date of the ExercisePlan. Accessor.
	std::string getPlanDate();
	// editGoal(), no parameters and return type void
	// Requests the number of steps to be edited into the current object, then uses member mutator to set goal steps.
	void editGoal(void);
	// toString(), no parameters, return type string
	// Utility function that returns concatenated string of the instance of the ExercisePlan.
	std::string toString(void);

private:
	// Data members
	int goalSteps;
	std::string planName;
	std::string planDate;
};

// Overloaded stream extraction operator to read ExercisePlan from file (fstream).
// Parameters reference to fstream lhs (left-hand side), reference to ExercisePlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs);
// Overloaded stream insertion operator to write ExercisePlan to console window.
// Parameters reference to ostream lhs (left-hand side), reference to ExercisePlan rhs (right-hand side)
// Returns modified lhs.
std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs);
// Overloaded stream insertion operator to write ExercisePlan to exercisePlans.txt (file).
// Parameters reference to fstream lhs (left-hand side), reference to ExercisePlan rhs (right-hand side)
// Returns modified lhs.
std::fstream & operator << (std::fstream &lhs, ExercisePlan &rhs);