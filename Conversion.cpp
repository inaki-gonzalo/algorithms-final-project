//Inaki Gonzalo
//id:1359345



//00000000001111111111222222222233333333334444444444555555555566
//01234567890123456789012345678901234567890123456789012345678901
//0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
#include <string>

#include <bitset>
#include <cmath>
#include "Conversion.h"
using namespace std;


int* Conversion::stringToBitseq(string s){
	int* temp=new int[16];
	int* buffer=new int[16*6];
	for(unsigned int m=0;m<16*6;m++){
		buffer[m]=0;
	}
	for(unsigned int i=0;i<s.length();i++){
		if(s[i]>='0'&& s[i]<='9'){
			temp[i]=s[i]-'0';
		}
		if(s[i]>='a'&& s[i]<='z'){
			temp[i]=s[i]-'a'+10;
		}
		if(s[i]>='A'&& s[i]<='Z'){
			temp[i]=s[i]-'A'+36;
		}
		temp[i]++;//shift all of them by one and avoid 0 mapped to 0
		int* array=NumToBitseq(temp[i]);
		for(int a=5;a>=0;a--){
			
			int flipA=5-a;
			buffer[(i*6)+flipA]=array[a]; //copy from array of a single character into main buffer(also flip order)
		}
		delete array;
		
	}
	delete temp;
	return buffer;
};
//Turns the integer n into a sequence of bits
int* Conversion::NumToBitseq(int n){
	if(n>63){
		return 0;
	}
	int* bs=new int[6]; //6 bits per character
	for(int a=0;a<6;a++){
		bs[a]=0;
	}
	int i=0;
	int n2;
	while (n > 0){
		n2 = n/2; // integer division: e. g. 5/2 = 2
		bs[i]=n - 2 * n2;
		n= n2;
		i++;
	}
	return bs;
};//end of numBitseq


int* Conversion::BitseqToDigitseq(int* array, int k){
	int* buffer=new int[16*6/(k)];//
	int index=0;
	for(int i=0;i<16*6/k;i++){
		buffer[index]=BitseqToBigNum(array+(i*k),k);
		index++;
	}
	return buffer;
	
};



int Conversion::BitseqToBigNum(int* bs,int k){
	int sum=0;
	for(int i=0;i<k;i++){
		sum=sum+(bs[i]*pow(2,k-(i+1)));
	}
	return sum;
};



