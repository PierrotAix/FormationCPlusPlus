// RangeBasedFor01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

template <typename T, int N>
void show(const tableau<T, N>& x)
{
	for (tableau<T, N>::const_iterator i = x.begin(); i != x.end(); i++) {
		cout << *i << endl;
	}
}

template <typename T>
void show(const vector<T>& x)
{
	for (vector<T>::const_iterator i = x.begin(); i != x.end(); i++) {
		cout << *i << endl;
	}
}


int main()
{
	tableau<int, 5> ints{ 10, 20, 30, 40, 50 };
	show(ints);

	cout << "*****" << endl;
	vector<string> s { "Monday", "Tuesday","Wednesday", "Thursday","Friday", "Saturday", "Sunday" };
	show(s);

	cout << "*****" << endl;
	tableau<string, 12> m { "January", "February","March", "April", "May",
		"June", "July", "August","September", "October","November", "December" };
	show(m);
	
	cout << "*****" << endl;

	return 0;
}

