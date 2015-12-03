//Inaki Gonzalo
//id:1359345



#include "SLItemList.h"
#include "Conversion.h"
#include <iostream>
#include <string>
#include <regex>
#include "UIMS.h"
#include <chrono>
using namespace std;
class tester{
SLItemList list;
UIMS table;
public:
void tt(){
	list.print();
	if(list.find("hello4")){
		cout<<"hello4 is there"<<endl;
	}
	else{
		cout<<"hello4 is NOT there"<<endl;
	}
	list.pushFront("hello",1);
	list.print();
	
	list.pushFront("hello2",2);
	list.print();
	list.pushFront("hello3",3);
	list.print();
	list.pushFront("hello4",4);
	list.print();
	if(list.find("hello4")){
		cout<<"hello4 is there"<<endl;
	}
	else{
		cout<<"hello4 is NOT there"<<endl;
	}
	
	
};
void testConversion(){
	Conversion c;
	c.stringToBitseq("moLLY1");
	
};
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
bool isValid(const string name){
	return name.length()<=16 && name.length()>0 && regex_match(name,regex("[[:alnum:]]+")); 
};
void testUIMS(int iterations){
	double sum=0;
	int counter=0;
	cout<<"UIMS test with "<<iterations<<" iterations"<<endl;
	for (int i=0;i<iterations;i++){
		string id=randId();
		if (isValid(id)&&table.isAvailable(id)){
			//cout<<"Name '"<<id<<"' is valid and available"<<endl;
			auto t1 = std::chrono::high_resolution_clock::now();
			table.add(id);
			auto t2 = std::chrono::high_resolution_clock::now();
			counter++;
			sum+=std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		}
	}
	table.status();
	//table.print();
	cout<<"average add time="<<sum/counter<<endl;
};


};
/*
int main(){
	tester t,t2,t3;
	//t.testConversion();
	
	//t.tt();
	t.testUIMS(100);
	t2.testUIMS(1000);
	t3.testUIMS(10000);
	//t.testUIMS(100000);
	//t.testUIMS(1000000);
	return 0;
}
*/
