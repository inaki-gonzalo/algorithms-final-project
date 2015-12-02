//Inaki Gonzalo
//id:1359345

#ifndef SITEM_H
#define SITEM_H

#include <string>

using namespace std;
class SItem{
private:
string uid;
int cid;
SItem* next;
public:
	SItem(string uid, int cid);
	string getUID() const;
	int getCID() const;
	SItem* getNext() const;
	void setNext(SItem* next);
	const string toString() const;

};
#endif //SITEM_H
