#include "../include/CyberPC.h"

CyberPC::CyberPC(string cyber_pc_os, string cyber_pc_name):
 	cyber_pc_os_(cyber_pc_os),
 	cyber_pc_name_(cyber_pc_name),
	cyber_pc_connections_(),
 	cyber_pc_time_to_infect_()
 	{}

const string CyberPC::getName(){
 	return cyber_pc_name_;
}

const string CyberPC::getOS(){
 	return cyber_pc_os_;
}

void CyberPC::AddConnection(string  second_pc){
 	cyber_pc_connections_.push_back(second_pc);
 	cout<<"\t"<<cyber_pc_name_<<" now connected to "<<second_pc<<endl;
}

void CyberPC::Infect(CyberWorm & worm){

	if (worm.getWormOS() == cyber_pc_os_) {
 		cyber_pc_time_to_infect_ = worm.getWormDormancyTime();
		delete cyber_worm_;
		cyber_worm_ = new CyberWorm(worm);

 		cout<<"\t\t"<<cyber_pc_name_<<" infected by "<<worm.getName()<<endl;
	}
	else cout<<"\t"<<"\tWorm "<<worm.getName()<<" is incompatible with "<<cyber_pc_name_<<endl;
}

void CyberPC::Run(const CyberDNS & server){
 	if (cyber_worm_ != NULL) {
 		if (cyber_pc_time_to_infect_> 0){
			cyber_pc_time_to_infect_= cyber_pc_time_to_infect_-1;
			cout<<"\t"<<cyber_pc_name_<<": Worm "<<cyber_worm_->getName()<<" is dormant"<<endl;
 		}
 		else {
 			cout<<"\t"<<cyber_pc_name_<<" infecting..."<<endl;
 			vector<string>::iterator it;
 			 for(it = cyber_pc_connections_.begin(); it != cyber_pc_connections_.end(); ++it) {
 			    (server.GetCyberPC(*it)).Infect(*cyber_worm_);
 			 }
 		}
 	}
}

void CyberPC::Disinfect(){
	if (cyber_worm_ != NULL){
		cyber_pc_time_to_infect_ = 0;
		string wormName = cyber_worm_->getName();
		delete cyber_worm_;
		cyber_worm_ = NULL;
		cout<<"\t\tWorm "<<wormName<<" successfully removed from "<<cyber_pc_name_<<endl;
	}
}

CyberPC::~CyberPC(){
	 delete (cyber_worm_);
}


