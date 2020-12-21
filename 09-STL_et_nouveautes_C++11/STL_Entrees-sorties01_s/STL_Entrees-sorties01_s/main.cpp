// STL_Entrees-sorties_s.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>

using namespace std;

const double pi = 3.141592654;
const int LL = 10;  // longueur maximale d'une ligne

int main() {
	int n = 64;

	// afficher la valeur de n en hexad�cimal
	cout << n << " en hexadecimal : " << hex << n << endl;

	// afficher la valeur de n en octal
	cout << n << " en octal : " << oct << n << endl;

	// afficher la valeur de n en d�cimal
	cout << n << " en decimal : " << dec << n << endl;

	// afficher la valeur de n en hexad�cimal sur 6 caract�res cadr�s � droite
	cout << n << " en hexadecimal : " << hex << setw(6) << n << endl;

	// afficher la valeur de n en hexad�cimal sur 6 caract�res cadr�s � droite en remplissant avec .
	cout << n << " en hexadecimal : " << hex << setfill('.') << setw(6) << n << endl;

	// afficher la valeur de pi par d�faut
	cout << pi << endl;                    // par d�faut 6 chiffres

										   // afficher la valeur de pi avec 9 chiffres significatifs
	cout << setprecision(9) << pi << endl; // on force � 9 chiffres

										   // afficher la valeur de pi/2 avec la m�me pr�cision
	cout << pi / 2.0 << endl;                // on reste � 9 chiffres

											 // afficher la valeur de pi avec 2 chiffres significatifs
	cout << setprecision(2) << pi << endl; // on force � 2 chiffres

										   // afficher chaque caract�re saisi au clavier
	cout << "saisir un mot (. pour quitter): ";
	char c;
	while (cin >> c) {
		if (c == '.') break;
		cout << c;
	}

	// afficher chaque caract�re saisi au clavier (en utilisant get)
	cout << "saisir a nouveau un mot (caractere . pour quitter):";
	while (cin.get(c)) {
		if (c == '.') break;
		cout << c;
	}
	// saisir une ligne de 10 caract�res maximum et l'afficher
	char ligne[LL];
	cout << "saisir encore un mot: ";
	cin >> setw(LL) >> ligne;
	cout << ligne << endl;

	// saisir une ligne de 10 caract�res maximum et l'afficher (en utilisant getline)
	cout << "saisir a nouveau un mot (avec getline): ";
	cin.getline(ligne, LL, '\n');
	cout << ligne << endl;

	return 0;
}

