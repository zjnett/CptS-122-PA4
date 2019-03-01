#pragma once

#include "PA4.h"

class DietPlan {
public:
	DietPlan();

	~DietPlan();

	DietPlan(int goal, std::string name, std::string date);

	DietPlan(DietPlan &old);

	void setGoalCalories(int goal);

	int getGoalCalories();

	void setPlanName(std::string plan);

	std::string getPlanName();

	void setPlanDate(std::string date);

	std::string getPlanDate();
private:
	int goalCalories;
	std::string planName;
	std::string planDate;
};