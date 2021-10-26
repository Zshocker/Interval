#pragma once
namespace Math {
	class Interval
	{
	private:
		double Min;
		double Max;
		bool RightOpen = false;
		bool leftOpen = false;
	public:
		Interval(double min, double max);
		Interval();
		Interval(double, bool, double, bool);
		double Maximum()const;
		double Minimum()const;
		bool Appartien(double num)const;
		Interval& operator+(const Interval& R2)const;
	};

}