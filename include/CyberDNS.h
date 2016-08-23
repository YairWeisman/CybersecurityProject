#ifndef CYBERDNS_H
#define CYBERDNS_H
#include <iostream>
#include <string>
#include <map>
#include "../include/CyberPC.h"
using namespace std;

class CyberPC; //Forward deceleration

class CyberDNS
{
private:
    map<const string, CyberPC *> cyber_DNS_;	//Hash map to hold PC names and pointers

 
public:
    //Constructor:
    CyberDNS();
    //Getters and Setters:
	void AddPC(CyberPC * cyber_pc_);	//Adding pointer to a PC
	CyberPC & GetCyberPC(const string cyber_pc_name) const;		//Returns a reference to a PC by name from map
	vector<string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.

	~CyberDNS();

};

#endif
