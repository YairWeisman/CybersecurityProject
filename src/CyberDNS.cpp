#include "../include/CyberDNS.h"

CyberDNS::CyberDNS():cyber_DNS_() {}

void CyberDNS::AddPC(CyberPC * cyber_pc_){
	cyber_DNS_[cyber_pc_->getName()]=cyber_pc_;
	cout<<cyber_pc_->getName()<<" connected to server" <<endl;
}

CyberPC & CyberDNS::GetCyberPC(const string cyber_pc_name) const{
	return * cyber_DNS_.find(cyber_pc_name)->second;
}


vector<string> CyberDNS::GetCyberPCList(){
  vector<string> pcList;
  map<const string, CyberPC*>::iterator it;
  for (it = cyber_DNS_.begin(); it != cyber_DNS_.end(); it++)
   	pcList.push_back(it->first);
  return pcList;
}

CyberDNS::~CyberDNS(){
	 vector<string> DeleteVector=GetCyberPCList();
	 for(int i=0;i<DeleteVector.size();++i){
		 CyberPC * temp = &GetCyberPC(DeleteVector[i]);
		 delete(temp);
	 }
	 cyber_DNS_.clear();
}

