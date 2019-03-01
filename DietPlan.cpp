#include "PA4.h"
#include "DietPlan.h"

DietPlan::DietPlan() {
	goalCalories = 0;
	planName = "";
	planDate = "";
}

DietPlan::~DietPlan() {
	//default destructor
}

DietPlan::DietPlan(int goal, std::string name, std::string date) {
	goalCalories = goal;
	planName = name;
	planDate = date;
}

DietPlan::DietPlan(DietPlan &old) {
	goalCalories = old.getGoalCalories();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}

void DietPlan::setGoalCalories(int goal) {
	if (goal < 0) {
		goalCalories = 0;
	} else {
		goalCalories = goal;
	}
}

int DietPlan::getGoalCalories() {
	return goalCalories;
}

void DietPlan::setPlanName(std::string plan) {
	planName = plan;
}

std::string DietPlan::getPlanName() {
	return planName;
}

void DietPlan::setPlanDate(std::string date) {
	planDate = date;
}

std::string DietPlan::getPlanDate() {
	return planDate;
}

std::fstream & operator >> (std::fstream &lhs, DietPlan &rhs) {
	std::string name;
	lhs >> name;
	int calories = 0;
	lhs >> calories;
	std::string date;
	lhs >> date;
	rhs.setPlanName(name);
	rhs.setGoalCalories(calories);
	rhs.setPlanDate(date);
	return lhs;
}

std::ostream & operator << (std::ostream &lhs, DietPlan &rhs) {
	lhs << "Diet Plan " << rhs.getPlanName() << " for " << rhs.getPlanDate() << ": Goal: " << rhs.getGoalCalories() << " calories";
	return lhs;
}
