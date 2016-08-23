#include "../include/CyberWorm.h"

CyberWorm::CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time):
	cyber_worm_os_(cyber_worm_os),
	cyber_worm_name_(cyber_worm_name),
	cyber_worm_dormancy_time_(cyber_worm_dormancy_time)
	{}

CyberWorm::CyberWorm(const CyberWorm& other):
	cyber_worm_os_(other.cyber_worm_os_),
	cyber_worm_name_(other.cyber_worm_name_),
	cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_)
	{}

const string CyberWorm::getName(){
	return cyber_worm_name_;
}

const string CyberWorm::getWormOS(){
	return cyber_worm_os_;
}

const int CyberWorm::getWormDormancyTime(){
	return cyber_worm_dormancy_time_;
}

CyberWorm::~CyberWorm(){}
