#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "../include/CyberWorm.h"
#include "../include/CyberDNS.h"
using namespace std;

class CyberDNS; // Forward decleration

class CyberPC
{
private:
    const string cyber_pc_os_;
    const string cyber_pc_name_;
    vector<string> cyber_pc_connections_;
    CyberWorm  * cyber_worm_ = NULL;
    int cyber_pc_time_to_infect_;
    CyberPC(); // Prevent the use of an empty constructor

public:
    //Constructor:
    CyberPC(string cyber_pc_os, string cyber_pc_name);
    //Getters and Setters:
    const string getName();
    const string getOS();
	void AddConnection(string  second_pc);				//Add a connection to this PC
	void Infect(CyberWorm & worm); 					//Add a worm to this PC

	void Run(const CyberDNS & server); 				//Activate PC and infect others if worm is active
	void Disinfect();											//Called by an expert to disinfect PC

	~CyberPC();
};


#endif

