// Decltype01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include "compteur.h"

using namespace std;

template <typename T1, typename T1> auto min(T1 &lhs, T1 &rhs) {
	if (lhs > rhs)
	{
		return rhs;
	}
	else
	{
		return lhs;
	}
};


int main()
{
	Compteur c{ 5 };
	int a{ 8 };
	auto min1 = min(c, a);
	cout << "min1: " << min1 << endl;

	double b{ 9.78 };
	auto min2 = min(a, b);
	cout << "min2: " << min2 << endl;

	string s1{ "alpha" }, s2{ "beta" };
	auto min3 = min(s1, s2);
	cout << "min3: " << min3 << endl;
	
	return 0;
}

