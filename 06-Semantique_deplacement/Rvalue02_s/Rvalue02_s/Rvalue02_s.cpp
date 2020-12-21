// Rvalue02_s.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

void print(vector<int> const& vect)
{
	cout << "{ ";
	for (int i : vect) {
		cout << i << ' ';
	}
	cout << "}\n";
}

int main()
{
	vector<int> source{ 1, 2, 3 };
	print(source);		// { 1 2 3 }
	
	vector<int> cp{ source };
	print(cp);			// { 1 2 3 }
	print(source);		// { 1 2 3 }
	
	vector<int> mv{ move(source) };
	print(mv);			// { 1 2 3 }
	print(source);		// { }
}
