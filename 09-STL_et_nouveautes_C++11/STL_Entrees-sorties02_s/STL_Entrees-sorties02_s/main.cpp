// STL_Entrees-sorties02_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_LIGNE = 80;

int main() {
	// ouvrir un fichier test.txt en écriture et en append
	ofstream fichierSortie("test.txt", ios::out | ios::app);

	// saisir quelques lignes et les recopier dans le fichier text.txt
	char mot[MAX_LIGNE];
	cout << "Entrez un texte (derniere ligne: &):" << endl;

	while (cin >> mot) {
		if (mot[0] == '&') break;
		fichierSortie << mot << endl;
	}

	fichierSortie.close();

	// ouvrir un fichier test.txt en lecture et afficher son contenu
	ifstream fichierEntree("test.txt");
	if (!fichierEntree) {
		cerr << "Impossible d'ouvrir le fichier test.txt" << endl;
		exit(EXIT_FAILURE);
	}
	int n = 0;
	while (fichierEntree >> mot) {
		cout << mot << endl;
		n++;
	}
	fichierEntree.close();
	cout << n << " lignes copiees..." << endl;

	return 0;
}
