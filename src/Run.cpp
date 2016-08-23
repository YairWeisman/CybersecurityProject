#include "../include/CyberPC.h"
#include "../include/CyberWorm.h"
#include "../include/CyberDNS.h"
#include "../include/CyberExpert.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH
using namespace std;


const string XML_PATH1 = "/users/studs/bsc/2016/yairweis/workspace/Assignment1/xml/computers.xml";
const string XML_PATH2 = "/users/studs/bsc/2016/yairweis/workspace/Assignment1/xml/network.xml";
const string XML_PATH3 = "/users/studs/bsc/2016/yairweis/workspace/Assignment1/xml/events.xml";

CyberDNS *dns = new CyberDNS();

void xml_load_computers(string XML_PATH){	//Reads the computers.xml file using 'Boost' library
	  using boost::property_tree::ptree;
	  ptree pt;
	  read_xml(XML_PATH, pt);
	  BOOST_FOREACH(ptree::value_type &root, pt.get_child("")){
		  boost::property_tree::ptree subtree = (boost::property_tree::ptree) root.second ;
		  CyberPC *PC = new CyberPC(subtree.get<string>("os"),subtree.get<string>("name") );
		  cout<<"Adding to server: "<<PC->getName()<<endl;
		  dns->AddPC(PC);
	  }
}

void xml_load_network(string XML_PATH){		//Reads the network.xml file using 'Boost' library and adding the connections
	  using boost::property_tree::ptree;
	  ptree pt;
	  read_xml(XML_PATH, pt);
	  BOOST_FOREACH(ptree::value_type &root, pt.get_child("")){
	  boost::property_tree::ptree subtree = (boost::property_tree::ptree) root.second ;
	  cout<<"Connecting "<<subtree.get<string>("pointA")<<" to "<<subtree.get<string>("pointB")<<endl;
	  (dns->GetCyberPC(subtree.get<string>("pointA"))).AddConnection(subtree.get<string>("pointB"));
	  (dns->GetCyberPC(subtree.get<string>("pointB"))).AddConnection(subtree.get<string>("pointA"));
	  }
}
void dayResults(){		//Runs the PCs at the end of any day
		vector<string> PCs = dns->GetCyberPCList();
		vector<string>::iterator it;
		for(it = PCs.end()-1; it != PCs.begin()-1; --it) {		//Iterate from Z to A
			(dns->GetCyberPC(*it)).Run(* dns);
		}
}

void expertsWorkDay(vector<CyberExpert*> ExpertsList){		//Activating experts that are on a work day
		vector<string> PCs = dns->GetCyberPCList();
		vector<string>::iterator it = PCs.end()-1;		//Iterate on PC list from Z to A
		int expertsListSize = ExpertsList.size();
		for(int j=0; j<expertsListSize; ++j) {
			CyberExpert *expert = ExpertsList[j];
			if ((expert->getWorkTime() >= expert->getWorkDay())){
				for(int n=0; n < expert->getEfficiency(); n++){
					if(it != PCs.begin()-1){	//If the experts efficiencies is small than the number of PCs
						expert->Clean(dns->GetCyberPC(*it));
						--it;
					}

				}
				if((expert->getWorkTime()==expert->getWorkDay()) && (expert->getRestTime()!=0))
					cout<<"\t"<<expert->getName()<<" is taking a break"<<endl;
				else if ((expert->getWorkTime()==expert->getWorkDay()) && (expert->getRestTime()==0)){
					expert->setWorkDay(1);
				}
				expert->setWorkDay(expert->getWorkDay()+1);
			}
			else {
				cout<<"\t"<<expert->getName()<<" is back to work"<<endl;
				expert->setWorkDay(1);
			}
		}
}

void xml_load_events(string XML_PATH){		//Reads the events.xml file using 'Boost' library and activate experts and PCs
	  using boost::property_tree::ptree;
	  ptree pt;
	  read_xml(XML_PATH, pt);
	  int day=0;
	  vector <CyberExpert*> ExpertsList ;
	  BOOST_FOREACH(ptree::value_type &root, pt.get_child("")){
		  ptree subtree = root.second;
		  if ((string)root.first.data()=="termination"){
			  int terminationDay = subtree.get<int>("time");
			  while(day <= terminationDay){
				  cout<< "Day : " << day << endl;
				  expertsWorkDay(ExpertsList);
				  dayResults();
				  day++;
			  }
		  }
		  else {
			  cout<< "Day : " << day << endl;	//Print what day it is
			  if ((string)root.first.data()=="hack"){
				  cout << "\tHack occured on " << subtree.get<string>("computer")<< endl;	//Prints if a computer is being hacked
				  string computer = subtree.get<string>("computer");
				  string wormName = subtree.get<string>("wormName");
				  int wormDormancy = subtree.get<int>("wormDormancy");
				  string wormOs = subtree.get<string>("wormOs");
				  CyberWorm * worm = new CyberWorm(wormOs, wormName, wormDormancy);
				  dns->GetCyberPC(computer).Infect(*worm);
				  delete worm;

			  }
			  if ((string)root.first.data()=="clock-in"){
				  string expertName = subtree.get<string>("name");
				  int expertWorkTime = subtree.get<int>("workTime");
				  int expertRestTime = subtree.get<int>("restTime");
				  int expertEfficiency = subtree.get<int>("efficiency");
				  CyberExpert * expert = new CyberExpert(expertName, expertWorkTime, expertRestTime, expertEfficiency);
				  ExpertsList.push_back(expert);
				  cout<<"\tClock-In: "<<expertName<<" began working"<<endl;
			  }
			  expertsWorkDay(ExpertsList);
			  dayResults();
			  day++;
		  }
	  }
	  int expertsListSize = ExpertsList.size();
	  for(int j=0; j<expertsListSize; ++j) {
	     delete(ExpertsList[j]);
	  }
}

int main(int argc, char *argv[]) {

	  xml_load_computers(XML_PATH1);
	  xml_load_network(XML_PATH2);
	  xml_load_events(XML_PATH3);

	  delete(dns);

	  return 0;
}
