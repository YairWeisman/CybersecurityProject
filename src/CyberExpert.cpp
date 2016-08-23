#include "../include/CyberExpert.h"

CyberExpert::CyberExpert(string cyber_expert_name, int cyber_expert_work_time, int cyber_expert_rest_time, int cyber_expert_efficiency):
	cyber_expert_name_(cyber_expert_name),
	cyber_expert_work_time_(cyber_expert_work_time),
	cyber_expert_rest_time_(cyber_expert_rest_time),
	cyber_expert_efficiency_(cyber_expert_efficiency),
	cyber_expert_work_day_(1)
	{}

void CyberExpert::Clean(CyberPC & cyber_pc){
	cout<<"\t"<<cyber_expert_name_<<" examining "<<cyber_pc.getName()<<endl;
	cyber_pc.Disinfect();
}

const string CyberExpert::getName() {
	return cyber_expert_name_;
}

const int CyberExpert::getWorkTime(){
	return cyber_expert_work_time_;
}

const int CyberExpert::getRestTime(){
	return cyber_expert_rest_time_;
}

const int CyberExpert::getEfficiency(){
	return cyber_expert_efficiency_;
}

int CyberExpert::getWorkDay(){
	return cyber_expert_work_day_;
}

void CyberExpert::setWorkDay(int number){
	cyber_expert_work_day_ = number;
}
CyberExpert::~CyberExpert(){}
