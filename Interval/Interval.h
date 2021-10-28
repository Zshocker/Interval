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
		Interval();
		Interval(double min, double max);
		Interval(double, bool, double, bool);
		double Maximum()const;
		double Minimum()const;
		bool Appartien(double num)const;
		bool isempty()const;
		//supposant que [] fait le meme traitement que Appartien
		bool operator[](double num)const;
		Interval& operator|(const Interval& R2)const;
		Interval& operator&(const Interval& R2)const;
		void print()const;
	};
}