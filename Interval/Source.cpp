#include"Interval.h"
#include<iostream>
using namespace std;
using namespace Math;
int main() 
{
	Interval Ne(13,true, 14,true);
	Interval NZ(14,true, 15,true);
	Interval NW = Ne & NZ;
	NW.print();
	return 1;
}