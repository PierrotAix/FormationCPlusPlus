// Lambda01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n{};
	auto carre = [](int a) {return a * a; };// A COMPLETER
	auto cube = [](int a) {return a * a * a; }; // A COMPLETER
	auto racine = [](int a) {return sqrt(a) ; };// A COMPLETER

	cout << "saisir un nombre entier:";
	cin >> n;
	cout << "carre de " << n << ": " << carre(n) << endl;
	cout << "cube de " << n << ": " << cube(n) << endl;
	cout << "racine carree de " << n << ": " << racine(n) << endl;

	cout << "fin ! " << endl;
	return 0;
}

