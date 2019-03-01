#include "PA4.h"
#include "FitnessAppWrapper.h"

using std::cout;
using std::endl;
using std::fstream;

FitnessAppWrapper::FitnessAppWrapper() { }

FitnessAppWrapper::~FitnessAppWrapper() { }

void FitnessAppWrapper::runApp(void) {
	DietPlan dietPlanList[7];
	ExercisePlan exercisePlanList[7];
	displayMenu();
}

void FitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, DietPlan &plan) {

}

void FitnessAppWrapper::loadWeeklyPlan(std::fstream &fileStream, DietPlan weeklyPlan[]) {

}

void FitnessAppWrapper::displayMenu(void) {
	cout << "\tFITNESS APPLICATION" << endl;
	cout << "1.    Load weekly diet plan from file." << endl;
	cout << "2.    Load weekly exercise plan from file." << endl;
	cout << "3.    Store weekly diet plan to file." << endl;
	cout << "4.    Store weekly exercise plan to file." << endl;
	cout << "5.    Display weekly diet plan to screen." << endl;
	cout << "6.    Display weekly exercise plan to screen." << endl;
	cout << "7.    Edit daily diet plan." << endl;
	cout << "8.    Edit daily exercise plan." << endl;
	cout << "9.    Exit." << endl;
}
