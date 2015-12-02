//Inaki Gonzalo
//id:1359345


#include <iostream>
#include <string>
#include <regex>
#include "UIMS.h"

using namespace std;
class interface{
private:
UIMS table;

//boolean is Valid
//checks names is between 1 and 16 characters long
//checks the characters are alpha numerical	
bool isValid(const string name){
	return name.length()<=16 && name.length()>0 && regex_match(name,regex("[[:alnum:]]+")); 
};
public:



void run(){
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
};


};
/*
int main()
{
	
	interface i;
	while(true){
		i.run();
		
	}
	
	return 0;
}
*/
