#ifndef CYBER_WORM
#define CYBER_WORM
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CyberWorm
{
private:
    const string 	cyber_worm_os_;
    const string 	cyber_worm_name_;
    const int 	cyber_worm_dormancy_time_;
    CyberWorm(); // Prevent the use of an empty constructor

public:
    //Constructor:
    CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time);
	CyberWorm(const CyberWorm& other); //copy constructor;
    //Getters and Setters:
	const string getName();
	const string getWormOS();
	const int getWormDormancyTime();

	~CyberWorm();
};


#endif
