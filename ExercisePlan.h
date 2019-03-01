#pragma once

#include "PA4.h"

class ExercisePlan {
public:
	ExercisePlan();

	ExercisePlan(int steps, std::string name, std::string date);

	ExercisePlan(ExercisePlan &old);

	~ExercisePlan();

	void setGoalSteps(int steps);

	int getGoalSteps();

	void setPlanName(std::string plan);

	std::string getPlanName();

	void setPlanDate(std::string date);

	std::string getPlanDate();

private:
	int goalSteps;
	std::string planName;
	std::string planDate;
};

std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs);
std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs);
