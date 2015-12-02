//Inaki Gonzalo
//id:1359345


#ifndef SLITEMLIST_H
#define SLITEMLIST_H

#include <string>
#include "SItem.h"
#include <iostream>
using namespace std;
class SLItemList{
	private:
	SItem* head;
	public:
	SItem* getHead();
	SLItemList();
	void pushFront(string uid,int cid);
	SItem* find(string uid);
	
	
	void print();
	
};
#endif 

