//Inaki Gonzalo
//id:1359345

#include "SItem.h"
#include <string>
#include "SLItemList.h"
#include <iostream>
#include "Conversion.h"
#include "UIMS.h"
using namespace std;


UIMS::UIMS(){
	size=2;
	table=new SLItemList[size];
	customerCount=0;
	salt=new int[16*6/4];//change 4 maybe
	UIMS::generateSalt();
	
}
void UIMS::generateSalt(){
	for(int i=0;i<16*6/4;i++){
		salt[i]=(rand() % (size-1))+1; //between 1 and (size-1)
		
	}
	
	
};
int UIMS::hash(const string uid){
	
	int index=0;
	Conversion c;
	int sum=0;
	int k=4;
	int* bitSequence=c.stringToBitseq(uid);
	int* intSequence=c.BitseqToDigitseq(bitSequence,k);//change 4 to some other number maybe?
	for(int i=0;i<16*6/k;i++){
		sum=sum+(intSequence[i]*salt[i]);
	}
	delete bitSequence;
	delete intSequence;
	index=sum%size;
	return index;
};
bool UIMS::isAvailable(const string uid){
	bool available=false;
	if(lookupCustomerId(uid)==0){
		available=true;
	}
	return available;
};

int UIMS::lookupCustomerId(const string uid){
	int id=0;
	int i=hash(uid);
	SLItemList tempList=table[i];
	SItem* customer=tempList.find(uid);
	if(customer!=0){
		id=customer->getCID();
	}
	return id;
}
double UIMS::load(){
	return (double)(customerCount)/size;
	
};

void UIMS::reallocate(){
	int oldSize=size;
	size*=2;
	generateSalt();
	SLItemList* tempTable=new SLItemList[size];
	for(int i=0;i<oldSize;i++){
		SItem* current=table[i].getHead();
		SItem* tempItem;
		if(current!=0){
			do{
				tempTable[hash(current->getUID())].pushFront(current->getUID(),current->getCID()); //rehash uid and insert it in apropriate list.
				tempItem=current->getNext();
				delete current;
				current=tempItem;
			}while(current!=0);//end of while
		}
	}
	delete table;
	table=tempTable;
};


void UIMS::add(const string uid){
	if(load()>0.75){
		reallocate();
	}
	table[hash(uid)].pushFront(uid,++customerCount);
};




void UIMS::print(){
	cout<<"Printing table"<<endl;
	for (int i=0;i<size;i++){
		cout<<"index["<<i<<"]:";
		table[i].print();
	}
};
void UIMS::status(){
	cout<<"customerCount: "<<customerCount<<endl;
	cout<<"size: "<<size<<endl;
	cout<<"load"<<load()<<endl;
	
};



