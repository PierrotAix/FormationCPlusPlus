// Constexpr01_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "Point.h"

using namespace std;

#include <array>

constexpr int pow(int base, int exp)  
{
	return (exp == 0 ? 1 : base * pow(base, exp - 1));
}

constexpr int factorielle(int n)
{
	return n > 1 ? (n * factorielle(n - 1)) : 1 ;
}

constexpr Point pointmilieu(const Point& p1, const Point& p2)
{
	return{ (p1.xValue() + p2.xValue()) / 2, 
		(p1.yValue() + p2.yValue()) / 2 };  
}

int main()
{
	constexpr int val = 4;               
	std::array<int, pow(3, val)> tableau1;
	cout << "taille de tableau1: " << tableau1.size() << endl;		
	
	constexpr int n = 3;
	std::array<int, factorielle(pow(2,n))> tableau2;
	cout << "taille de tableau2: " << tableau2.size() << endl;
	
	constexpr Point p1(9.4, 27.7);
	constexpr Point p2(28.8, 5.3);
	constexpr Point milieu = pointmilieu(p1, p2);
	
	cout << "Point milieu: x=" << milieu.xValue() << ", y=" << milieu.yValue() << endl;

	return 0;
}
