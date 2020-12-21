// Rvalue01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
//#include "Rvalue01.h"

using namespace std;

void print(const string& valeur) {
	cout << valeur << endl;
}

void print(string&& valeur) {
	cout << valeur << endl;
}

int main()
{
	string a{ "a" }, b{ "b" }, c{ "c" };

	print(a);					// a
	print(a + b);				// ab
	print(std::move(a));		// a
	print(std::move(a + b));	// ab
	print(a + std::move(b));	// ab
	print(a + b + c);			// ac // pourquoi b a disparu ? // car a la ligne du dessus ça a été supprimé

	return 0;
}
