// Decltype01_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include "compteur.h"

using namespace std;


/*
template<class A, class B>
auto min(A& a, B& b) -> decltype(a < b ? a : b)
{
	return (a < b) ? a : b;
}


#define MIN(x,y) ( (x) < (y) ? (x) : (y))

template<class A, class B>
auto min(A& a, B& b) -> decltype(MIN(a,b))
{
	return MIN(a,b);
}*/

/*
template<typename A, typename B>
auto min(const A& a, const B& b) -> decltype((a) < (b) ? (a) : (b))
{
	return (a) < (b) ? (a) : (b);
}
*/

template<class A, class B>
auto min(const A& a, const B& b)
{
	return (a) < (b) ? (a) : (b);
}



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

