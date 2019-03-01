#pragma once

#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper {
public:
	FitnessAppWrapper();

	~FitnessAppWrapper();

	void runApp(void);

	int getInt(void);

	void pauseForInput(void);

	void loadDailyPlan(std::fstream &fileStream, DietPlan &plan);

	void loadDailyPlan(std::fstream &fileStream, ExercisePlan &plan);

	void loadWeeklyPlan(std::fstream &fileStream, DietPlan weeklyPlan[]);

	void loadWeeklyPlan(std::fstream &fileStream, ExercisePlan weeklyPlan[]);

	void displayDailyPlan(DietPlan &plan);

	void displayDailyPlan(ExercisePlan &plan);

	void displayWeeklyPlan(DietPlan weeklyPlan[]);

	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

	void displayMenu(void);

private:

};
