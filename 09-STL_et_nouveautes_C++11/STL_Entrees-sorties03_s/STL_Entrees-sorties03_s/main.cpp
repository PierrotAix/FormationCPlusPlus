// STL_Entrees-sorties03_s.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const char TAB = '\t';
const short TAILLE_MATR = 10;
const short TAILLE_NOM = 20;
const short TAILLE_SALAIRE = 10;

struct Employe {
	int matricule;
	char nom[TAILLE_NOM];
	long unsigned int salaire;
};
const int TAILLE_ENREG = TAILLE_MATR + (TAILLE_NOM + 1) + TAILLE_SALAIRE
+ 2 * sizeof(TAB) + sizeof('\n');

bool rechercheEmploye(ifstream& fichEntree, int matricule, Employe& empl) {
	/* recherche s�quentielle sur le matricule */
	fichEntree.clear();           // effacer les indicateurs du fichier
	fichEntree.seekg(0);          // se positionner au d�but du fichier
	bool trouve = false;
	while ((!fichEntree.eof()) && (!trouve)) {
		fichEntree >> empl.matricule;
		if (empl.matricule == matricule)  trouve = true;
		fichEntree >> ws;
		fichEntree >> empl.nom;
		fichEntree >> ws;
		fichEntree >> empl.salaire;
		fichEntree >> ws;
	}
	return trouve;
}


bool accesEmploye(ifstream& fichEntree, unsigned int numero, Employe& empl) {
	/* acc�s direct aux enregistrements du fichier */
	fichEntree.clear();    // effacer les indicateurs du fichier
	fichEntree.seekg((numero - 1)*TAILLE_ENREG);
	if (fichEntree.peek() == EOF) return false;
	fichEntree >> empl.matricule;
	fichEntree >> ws;
	fichEntree >> empl.nom;
	fichEntree >> ws;
	fichEntree >> empl.salaire;
	fichEntree >> ws;
	return true;
}

void ecrireEmploye(ofstream& fichSortie, const Employe& e) {
	fichSortie << setw(TAILLE_MATR) << e.matricule;
	fichSortie << TAB;
	fichSortie << setw(TAILLE_NOM) << e.nom;
	fichSortie << TAB;
	fichSortie << setw(TAILLE_SALAIRE) << e.salaire << endl;
}

void lireEmploye(ifstream& fichEntree, Employe& empl) {
	fichEntree >> empl.matricule;
	fichEntree >> ws;
	fichEntree >> empl.nom;
	fichEntree >> ws;
	fichEntree >> empl.salaire;
	fichEntree >> ws;    // lire fin de ligne
}

void afficheEmploye(const Employe& e) {
	cout << e.matricule << TAB << e.nom << TAB << e.salaire << endl;
}

Employe empl1 = { 7, "Nino", 100000L };
Employe empl2 = { 2, "Laurent", 70000L };
Employe empl3 = { 3, "Julien", 50000L };
Employe empl4 = { 12, "Anne", 90000L };
Employe empl5 = { 30, "Lisete", 110000L };
Employe empl6 = { 35, "Dominique", 40000L };
Employe empl7 = { 39, "Lina", 0L };

int main() {

	/* cr�ation du fichier */
	ofstream fichSortie("employe.dat");
	ecrireEmploye(fichSortie, empl1);
	ecrireEmploye(fichSortie, empl2);
	ecrireEmploye(fichSortie, empl3);
	ecrireEmploye(fichSortie, empl4);
	ecrireEmploye(fichSortie, empl5);
	ecrireEmploye(fichSortie, empl6);
	ecrireEmploye(fichSortie, empl7);
	fichSortie.close();

	ifstream fichEntree("employe.dat");
	if (!fichEntree) {
		cerr << "Impossible d'ouvrir EMPLOYE.DAT" << endl;
		exit(EXIT_FAILURE);
	}

	/* lecture s�quentielle du fichier */
	Employe empl;
	while (fichEntree.peek() != EOF) {
		lireEmploye(fichEntree, empl);
		afficheEmploye(empl);
	}

	/* recherches s�quentielles dans le fichier */
	int matr;
	cout << "Entrez un matricule, -1 pour terminer " << flush;
	cin >> matr;
	while (matr != -1) {
		if (rechercheEmploye(fichEntree, matr, empl)) {
			afficheEmploye(empl);
		}
		else {
			cout << matr << " n'existe pas dans EMPLOYE.DAT" << endl;
		}
		cout << "Entrez un matricule, -1 pour terminer " << flush;
		cin >> matr;
	}


	/* acc�s directs dans le fichier */
	cout << "Num�ro d'enregistrement (-1 pour terminer) ?" << flush;
	int num;
	cin >> num;
	while (num != -1) {
		if (accesEmploye(fichEntree, num, empl)) {
			afficheEmploye(empl);
		}
		else {
			cout << num << " n'existe pas dans EMPLOYE.DAT" << endl;
		}
		cout << "Num�ro d'enregistrement (-1 pour terminer) ? " << flush;
		cin >> num;
	}

	fichEntree.close();
}
