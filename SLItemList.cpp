//Inaki Gonzalo
//id:1359345



#include <string>
#include "SItem.h"
#include "SLItemList.h"
#include <iostream>
#include <fstream>
using namespace std;

SLItemList::SLItemList(){
	head=0;
}
SItem* SLItemList::getHead(){
	return head;
}
void SLItemList::pushFront(string uid,int cid){
	SItem* temp=new SItem(uid,cid);
	temp->setNext(head);
	head=temp;
};
SItem* SLItemList::find(string uid){
	SItem* item=0;
	if(head==0){
		return item;
	}
	SItem* current=head;
	bool found=false; 
	do{
		if(current->getUID()==uid){
			found=true;
			item=current;
		}//end of if
		current=current->getNext();
	}while(current!=0&&found==false);//end of while
	return item;
}//end of find
void SLItemList::print(){
	if(head==0){
		cout<<"head ==0"<<endl;
		return;
	}
	SItem* current=head;
	do{
		cout<<current->toString();
		current=current->getNext();
		if(current!=0){
			cout<<", ";
		}
			
	}while(current!=0);
	cout<<endl;
	
};
string SLItemList::toString(){
	string buffer="";
	if(head==0){
		return buffer;
	}
	
	SItem* current=head;
	do{
		buffer+=current->toString();
		current=current->getNext();
		if(current!=0){
			buffer+=", ";
		}
			
	}while(current!=0);
	buffer+="\n";
	return buffer;
	
};//end of print


