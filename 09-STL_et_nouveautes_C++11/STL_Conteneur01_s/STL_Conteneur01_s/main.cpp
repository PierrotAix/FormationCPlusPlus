// STL_Conteneur01_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maximum = 10;

int main() {

	// déclarer un tableau t (type vector) de 10 entiers
	vector<int> t(maximum);

	int i;

	// en utilisant la notation [], remplir le tableau t avec des entiers 
	// de valeur aléatoire (entre 0 et 100)
	for (i = 0; i < maximum; ++i) {
		t[i] = rand() % 100;
	}

	// trier le tableau t dans l'ordre croissant (sort)
	sort(t.begin(), t.end());

	// afficher le tableau t à l'aide d'une boucle en utilisant la notation []
	for (i = 0; i < maximum; ++i) {
		cout << t[i] << ' ';
	}
	cout << endl;

	// afficher le tableau t à l'aide d'un itérateur
	vector<int>::iterator j,k;
	for (j = t.begin(); j != t.end(); ++j) {
		cout << *j << ' ';
	}
	cout << endl;

	// redimensionner le tableau t
	t.resize(15, 3);

	// afficher le nombre d'éléments
	cout << "Taille actuelle : " << t.size() << endl;
	
	// ré-afficher le tableau à l'aide d'un itérateur
	for (j = t.begin(); j != t.end(); ++j) {
		cout << *j << ' ';
	}
	cout << endl;

	// créer un tableau u de 20 entiers initialisé à la valeur -1
	vector<int> u(20, -1);

	cout << "Taille actuelle de u : " << u.size() << endl;
	// afficher le tableau u à l'aide d'un itérateur
	for (k = u.begin(); k != u.end(); ++k) {
		cout << *k << ' ';
	}
	cout << endl;

	// affecter le tableau t au tableau u
	u = t;

	cout << "Taille actuelle de u : " << u.size() << endl;
	for (k = u.begin(); k != u.end(); ++k) cout << *k << ' ';
	cout << endl;

	// effacer le contenu du vecteur u
	u.clear();
	
	cout << "Taille actuelle de u : " << u.size() << endl;
	for (k = u.begin(); k != u.end(); ++k) cout << *k << ' ';
	cout << endl;

	// insérer les valeurs 5, 2, 1, 3 à la fin du tableau u
	u.insert(u.end(), 5);
	u.insert(u.end(), 2);
	u.insert(u.end(), 1);
	u.insert(u.end(), 3);

	// trier le tableau u dans l'ordre croissant (sort)
	sort(u.begin(), u.end());

	// permuter le contenu des tableaux t et u
	t.swap(u);
	
	// ré-afficher les tableaux à l'aide d'un itérateur
	cout << "Taille actuelle de t: " << t.size() << endl;
	for (j = t.begin(); j != t.end(); ++j) {
		cout << *j << ' ';
	}
	cout << endl;
	cout << "Taille actuelle de u: " << u.size() << endl;
	for (k = u.begin(); k != u.end(); ++k) {
		cout << *k << ' ';
	}
	cout << endl;

	// supprimer le premier élément du tableau
	u.erase(u.begin());

	// ré-afficher le tableau u à l'aide d'un itérateur, en commençant par la fin
	vector<int>::reverse_iterator m;
	for (m = u.rbegin(); m != u.rend(); ++m) {
		cout << *m << ' ';
	}
	cout << endl;

	// affichage du premier et du dernier élément
	cout << "Front u " << u.front() << " back u " << u.back() << endl;

	// u.pop_front();     pas permis sur un vector
	
	// supprimer le dernier élément du tableau u
	u.pop_back();      // supprimer le dernier élément du tableau 

	// u.push_front(100); pas permis sur un vector
	
	// insérer la valeur 1000 à la fin du tableau u
	u.push_back(1000); // insérer la valeur 1000 à la fin du tableau

	// afficher le tableau u à l'aide d'un itérateur
	for (k = u.begin(); k != u.end(); ++k) {
		cout << *k << ' ';
	}
	cout << endl;

	//cout << u[-1] << endl;    // pas de contrôle     DANGER
							  //cout << u.at(-1) << endl; // exception out_of_range !
}
