#pragma once

#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper {
public:
	FitnessAppWrapper();

	~FitnessAppWrapper();

	void runApp(void);

	int getInt(void);
	
	void loadDailyPlan(std::fstream &fileStream, DietPlan &plan);

	void loadWeeklyPlan(std::fstream &fileStream, DietPlan weeklyPlan[]);

	void displayMenu(void);

private:

};
