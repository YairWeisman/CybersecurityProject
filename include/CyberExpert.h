#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/CyberPC.h"
using namespace std;

class CyberExpert
{
private:
	const string cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    int cyber_expert_work_day_;
    CyberExpert(); // Prevent the use of an empty constructor

public:
    //Constructor:
    CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
	//Getters and Setters:
 	const string getName();
	const int getWorkTime();
	const int getRestTime();
	const int getEfficiency();
	int getWorkDay();
	void setWorkDay(int number);

 	void Clean(CyberPC & cyber_pc);		//A call for the expert to disinfect a PC
	~CyberExpert();
};


#endif
