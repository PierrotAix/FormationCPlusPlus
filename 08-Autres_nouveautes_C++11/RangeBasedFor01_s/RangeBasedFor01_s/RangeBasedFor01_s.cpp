// RangeBasedFor01_s.cpp : définit le point d'entrée pour l'application console.
// https://oopscenities.net/2011/06/09/c0x-range-based-for-loop/

#include "stdafx.h"
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

/*
template <typename T>
void show(const T& x)
{
	for (auto& i = x.begin(); i != x.end(); i++) {
		cout << *i << endl;
	}
}
*/

template <typename T>
void show(const T& x)
{
	for (const auto& i : x) {
		cout << i << endl;
	}
}


int main()
{
	array<int,5> ints{ 10, 20, 30, 40, 50 };
	show(ints);

	cout << "*****" << endl;
	vector<string> s { "Monday", "Tuesday","Wednesday", "Thursday","Friday", "Saturday", "Sunday" };
	show(s);
	
	cout << "*****" << endl;
	array<string, 12> m { "January", "February","March", "April", "May",
						"June", "July", "August","September", "October","November", "December" };
	show(m);
	
	cout << "*****" << endl;

	return 0;
}

