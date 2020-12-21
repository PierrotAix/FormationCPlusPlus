// Lambdas01_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n{};
	auto carre = [](int x) { return x * x; };
	//auto cube = [](int x) { return x * x * x; };
	auto cube = [&carre](int x) { return x * carre(x); };
	auto racine = [](int x) { return sqrt(x); };

	cout << "saisir un nombre entier:";
	cin >> n;
	cout << "carre de " << n << ": " << carre(n) << endl;
	cout << "cube de " << n << ": " << cube(n) << endl;
	cout << "racine carree de " << n << ": " << racine(n) << endl;

	cout << "fin ! " << endl;
	return 0;
}

