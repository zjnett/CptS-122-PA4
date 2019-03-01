#pragma once

#include "DietPlan.h"

class FitnessAppWrapper {
public:
	FitnessAppWrapper();

	~FitnessAppWrapper();

	void runApp(void);

	void loadDailyPlan(std::fstream &fileStream, DietPlan &plan);

	void loadWeeklyPlan(std::fstream &fileStream, DietPlan weeklyPlan[]);

	void displayMenu(void);

private:

};