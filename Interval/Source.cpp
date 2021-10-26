#include"Interval.h"
using namespace Math;
int main() {
	Interval Ne(15, 20);
	Interval NZ(10, 15);
	Interval NW = Ne + NZ;
	NW.print();
	return 1;
}