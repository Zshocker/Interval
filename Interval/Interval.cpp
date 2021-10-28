#include <iostream>
#include "Interval.h"
#include<assert.h>
using namespace Math;
using namespace std;
Math::Interval::Interval(double min, double max)
{
    assert(min <= max);
    this->Min = min;
    this->Max = max;
}
Math::Interval::Interval()
{
    this->Max = 0;
    this->Min = 0; 
    this->leftOpen = true;
    this->RightOpen = true;
}
Math::Interval::Interval(double min, bool Lopen, double max, bool Ropen)
{
    assert(min <= max);
    this->leftOpen = Lopen;
    this->RightOpen = Ropen;
    this->Min = min;
    this->Max = max;
}

Math::Interval& Math::Interval::operator|(const Interval& R2) const
{
    if (this == &R2) { 
        return *(new Interval(*this)); 
    }
   if (this->Appartien(R2.Min) && this->Appartien(R2.Max))return *(new Interval(*this)); 
   if (R2.Appartien(this->Min) && R2.Appartien(this->Max))return *(new Interval(R2)); 
   if (this->Max<R2.Min || this->Min>R2.Max)return *(new Interval);
   Interval* New = new Interval;
   if (this->Max < R2.Max) 
   {
       New->Max = R2.Max;
       New->RightOpen = R2.RightOpen;
   }
   else if (this->Max > R2.Max) 
   {
       New->Max = this->Max;
       New->RightOpen = this->RightOpen;
   }
   else {
       New->Max = this->Max;
       if(this->RightOpen && R2.RightOpen)New->RightOpen = true;
   }
   if (this->Min > R2.Min)
   {
       New->Min = R2.Min;
       New->leftOpen = R2.leftOpen;
   }
   else if (this->Min < R2.Min) {
       New->Min = this->Min;
       New->leftOpen = this->leftOpen;
   }
   else 
   {
       New->Min = this->Min;
       if (this->leftOpen && R2.leftOpen)New->leftOpen = true;
   }
   return  *New;
}

Interval& Math::Interval::operator&(const Interval& R2) const
{
    if (this->Max<R2.Min || this->Min>R2.Max)return *(new Interval);
    if (this->Appartien(R2.Min) && this->Appartien(R2.Max))return *(new Interval(R2));
    if (R2.Appartien(this->Min) && R2.Appartien(this->Max))return *(new Interval(*this));
    Interval* New = new Interval;
    if (this->Max < R2.Max)
    {
        New->Max = this->Max;
        New->RightOpen = this->RightOpen;
    }
    else if (this->Max > R2.Max)
    {
        New->Max = R2.Max;
        New->RightOpen = R2.RightOpen;
    }
    else {
        New->Max = this->Max;
        if (this->RightOpen || R2.RightOpen)New->RightOpen = true;
    }
    if (this->Min > R2.Min)
    {
        New->Min = this->Min;
        New->leftOpen = this->leftOpen;
    }
    else if (this->Min < R2.Min) {
        New->Min = R2.Min;
        New->leftOpen = R2.leftOpen;
    }
    else
    {
        New->Min = this->Min;
        if (this->leftOpen || R2.leftOpen)New->leftOpen = true;
    }
    return  *New;
}

void Math::Interval::print() const
{
    if (this->isempty()) 
    {
        cout <<"interval Vide ";
    }
    char c,c2;
    if (this->leftOpen) c = ']';
    else  c = '[';
    if (this->RightOpen) c2 = '[';
    else c2 = ']';
    cout << c << this->Min << " , " << this->Max << c2 << endl;
}

double Math::Interval::Maximum()const
{
    return this->Max;
}

double Math::Interval::Minimum()const
{
    return this->Min;
}

bool Math::Interval::Appartien(double num)const
{

    if (this->leftOpen && this->Min >= num)return false;
    if (!this->leftOpen && this->Min > num)return false;
    if (this->RightOpen && this->Max <= num)return false;
    if (!this->RightOpen && this->Max < num)return false;
    return true;
}

bool Math::Interval::isempty() const
{
    if (this->Max == this->Min && this->leftOpen && this->RightOpen)return true;
    return false;
}

bool Math::Interval::operator[](double num) const
{
    return this->Appartien(num);
}
