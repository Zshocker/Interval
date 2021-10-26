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
		Interval(double min=0, double max=0);
		Interval(double, bool, double, bool);
		double Maximum()const;
		double Minimum()const;
		bool Appartien(double num)const;
		//supposant que [] fait le meme traitement que Appartien
		bool operator[](double num)const;
		Interval& operator+(const Interval& R2)const;
		void print()const;
	};
}