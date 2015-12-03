//Inaki Gonzalo
//id:1359345

#include "SItem.h"
#include <string>
using namespace std;


SItem::SItem(string uid, int cid){
	this->uid=uid;
	this->cid=cid;
	next=0;
};

string SItem::getUID() const{
	return uid;
};
int SItem::getCID() const{
	return cid;
};
SItem* SItem::getNext() const{
	return next;
};
void SItem::setNext(SItem* next){
	this->next=next;
};
const string SItem::toString() const {
	return uid;
};


