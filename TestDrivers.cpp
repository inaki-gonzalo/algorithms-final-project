//Inaki Gonzalo
//id:1359345
//Jonathan Beebout
//id:1438806
//Miriam Ali


#include <iostream>
#include <string>
#include <regex>
#include "UIMS.h"
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;
class TestDrivers{
private:
UIMS table;

//boolean is Valid
//checks names is between 1 and 16 characters long
//checks the characters are alpha numerical	
bool isValid(const string name){
	return name.length()<=16 && name.length()>0 && regex_match(name,regex("[[:alnum:]]+")); 
};
public:
string randId(){
	string uid;
	int length=rand() % 16 +1;
	for(int i=0;i<length;i++){
		int var=rand()%3;
		switch(var){
			case 0://lower case character
				uid+=(char)(rand() % ('z'-'a')+'a');
			break;
			case 1://Upper case character
				uid+=(char)(rand() % ('Z'-'A')+'A');
			break;
			case 2://digits
				uid+=(char)(rand() % ('9'-'0')+'0');
			break;
				
		}
	}
	return uid;
};
void testUIMS(int iterations){
	double sum=0;
	int counter=0;
	cout<<"UIMS test with "<<iterations<<" iterations"<<endl;
	for (int i=0;i<iterations;i++){
		string id=randId();
		if (isValid(id)&&table.isAvailable(id)){
			auto t1 = std::chrono::high_resolution_clock::now();
			table.add(id);
			auto t2 = std::chrono::high_resolution_clock::now();
			counter++;
			sum+=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		}
	}
	table.status();
	cout<<"average add time="<<sum/counter<<endl;
};


void run(){
	cout<<endl<<"What would you like to do?"<<endl;
	cout<<"i:insert"<<endl;
	cout<<"t: run tests"<<endl;
	cout<<"s: stats"<<endl;
	cout<<"f: read from file"<<endl;
	string response;
	cin>>response;
	if(response=="i"){
		string name="";
		cout<<"Enter name: "<<endl;
		cin>>name;
		if (isValid(name)&&table.isAvailable(name)){
			cout<<"Name '"<<name<<"' is valid and available"<<endl;
			table.add(name);
			
		}
		else{
			cout<<"Name '"<<name<<"' is NOT valid or available"<<endl;
		}
		table.print();	
	}
	else if(response=="t"){
		testUIMS(100);
		testUIMS(1000);
	}
	else if(response=="s"){
		table.status();
	}
	else if(response=="f"){//reading from file
		string name="";
		ifstream fileio ("INPUT");
		stringstream ss;
		while (getline(fileio,name)) {
			if (isValid(name)&&table.isAvailable(name)){

				table.add(name);
				
			}
		}
		table.printToFile();
		cout<<"Printed to file"<<endl;	
		
	}
	
};


};

int main()
{
	
	TestDrivers t;
	while(true){
		t.run();
		
	}
	
	return 0;
}

