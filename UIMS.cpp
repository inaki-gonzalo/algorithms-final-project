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
	size2Power=2;
	table=new SLItemList[size];
	customerCount=0;
	salt=0;//point it to null
	UIMS::generateSalt();
	
}
void UIMS::generateSalt(){
	k=(int)log2(size);
	delete salt;
	salt=new int[16*6/k];
	for(int i=0;i<16*6/k;i++){
		salt[i]=(rand() % (size-1))+1; //between 1 and (size-1)
		
	}
	
	
};
int UIMS::hash(const string uid){
	int index=0;
	Conversion c;
	int sum=0;
	int* bitSequence=c.stringToBitseq(uid);
	int* intSequence=c.BitseqToDigitseq(bitSequence,k);
	for(int i=0;i<16*6/k;i++){//length of the salt
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
	size2Power*=2;
	size=closestPrime(size2Power);
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
	++customerCount;
	if(load()>0.75){
		reallocate();
	}
	table[hash(uid)].pushFront(uid,customerCount);
};




void UIMS::print(){
	cout<<"Printing table"<<endl;
	for (int i=0;i<size;i++){
		if(table[i].getHead()!=0){
			cout<<"index["<<i<<"]:";
			table[i].print();
		}
	}
};
void UIMS::status(){
	cout<<"customerCount: "<<customerCount<<endl;
	cout<<"size: "<<size<<endl;
	cout<<"load: "<<load()<<endl;
	
};
void UIMS::stats(){
	int longestListSize=0;
	for(int i=0;i<size;i++){
		SItem* current=table[i].getHead();
		SItem* tempItem;
		int counter=0;
		if(current!=0){
			do{
				counter++;
				tempItem=current->getNext();
				delete current;
				current=tempItem;
			}while(current!=0);//end of while
			counter--;
			if(longestListSize<counter){
				longestListSize=counter;
			}
		}
	}
	status();
	cout<<"longest List Size="<<longestListSize<<endl;
	
};



int UIMS::closestPrime(int number) {

    int nonPrime = number;

    int primes[] = {5,11,17,37,67,131,257,521,1031,2053,4099};

    for (int i = 0; i < 11; i++) {

        if (primes[i] > nonPrime) {


            return primes[i];

        }

    }

    return number;

}; 


