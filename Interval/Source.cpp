#include"Interval.h"
#include<iostream>
using namespace Math;
int main() {
	Interval Ne(15, 20);
	Interval NZ(10, 15);
	Interval NW = Ne + NZ;
	return 1;
}