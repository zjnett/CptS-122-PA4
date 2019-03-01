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