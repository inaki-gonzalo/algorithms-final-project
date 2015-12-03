//Inaki Gonzalo
//id:1359345

#ifndef UIMS_H
#define UIMS_H

#include "SItem.h"
#include <string>
#include "SLItemList.h"
#include <iostream>
#include "Conversion.h"
using namespace std;
class UIMS{
int size;
int size2Power;
int k;
int customerCount;
int* salt;
SLItemList* table;

public:
UIMS();
int hash(const string uid);
bool isAvailable(const string uid);
int lookupCustomerId(const string uid);
double load();
void reallocate();
void add(const string uid);
void generateSalt();
void print();
void status();
void stats();
int closestPrime(int powerOfTwo);
};
#endif 


