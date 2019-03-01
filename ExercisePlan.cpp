#include "PA4.h"
#include "ExercisePlan.h"

ExercisePlan::ExercisePlan() {
	goalSteps = 0;
	planName = "";
	planDate = "";
}

ExercisePlan::ExercisePlan(int steps, std::string name, std::string date) {
	goalSteps = steps;
	planName = name;
	planDate = date;
}

ExercisePlan::ExercisePlan(ExercisePlan &old) {
	goalSteps = old.getGoalSteps();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}

ExercisePlan::~ExercisePlan() {
	//default destructor
}

void ExercisePlan::setGoalSteps(int steps) {
	if (steps < 0) {
		goalSteps = 0;
	} else {
		goalSteps = steps;
	}
}

int ExercisePlan::getGoalSteps() {
	return goalSteps;
}

void ExercisePlan::setPlanName(std::string plan) {
	planName = plan;
}

std::string ExercisePlan::getPlanName() {
	return planName;
}

void ExercisePlan::setPlanDate(std::string date) {
	planDate = date;
}

std::string ExercisePlan::getPlanDate() {
	return planDate;
}

std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs) {
	std::string name;
	lhs >> name;
	int steps = 0;
	lhs >> steps;
	std::string date;
	lhs >> date;
	rhs.setPlanName(name);
	rhs.setGoalSteps(steps);
	rhs.setPlanDate(date);
	return lhs;
}
