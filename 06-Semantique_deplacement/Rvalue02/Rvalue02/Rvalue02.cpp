// Rvalue02.cpp : définit le point d'entrée pour l'application console.
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

	// COMPLETER : créer par déplacement un vector mv à partir du vector source
	vector<int> mv { move(source)}; // a refaire
	
	print(mv);			// { 1 2 3 }
	print(source);		// { }
}
