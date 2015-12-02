//Inaki Gonzalo
//id:1359345


#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <bitset>
#include <cmath>
using namespace std;

class Conversion{
public:
int* stringToBitseq(string s);
//Turns the integer n into a sequence of bits
int* NumToBitseq(int n);

int* BitseqToDigitseq(int* array, int k);

int BitseqToBigNum(int* bs,int k);


};
#endif 
