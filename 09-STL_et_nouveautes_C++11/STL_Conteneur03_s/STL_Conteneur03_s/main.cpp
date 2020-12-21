// STL_Conteneur03_s.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <utility>

using namespace std;

struct Personne {
	int age;
	string nom;
	Personne(int, string);
};

Personne::Personne(int a = 18, string n = "") : age(a), nom(n) {
}

typedef map<int, Personne, greater<int> > PersonneMap;
typedef PersonneMap::value_type valeurPersonneMap;


void afficher(const PersonneMap& s) {
	PersonneMap::const_iterator i;

	// va les afficher dans l'ordre decroissant � cause de greater
	for (i = s.begin(); i != s.end(); ++i) {
		cout << (*i).first << '\t' << (*i).second.nom
			<< ' ' << (*i).second.age << endl;
	}
	cout << "La map contient " << s.size() << " elements" << endl;
}

int main() {
	// d�finir une map m d'objets Personne avec cl� de comparaison greater
	PersonneMap m;

	// ins�rer 4 objets Personne
	m.insert(valeurPersonneMap(12, Personne(38, "Nino")));
	m.insert(valeurPersonneMap(214, Personne(10, "Julien")));
	m.insert(valeurPersonneMap(61, Personne(9, "Laurent")));
	m.insert(valeurPersonneMap(1, Personne(3, "Lina")));

	// intercepter une tentative d'insertion d'une valeur d�j� pr�sente (cl� d�j� utilis�e)
	pair<PersonneMap::iterator, bool> p
		= m.insert(valeurPersonneMap(1, Personne(37, "Dominique")));
	if (!p.second)
		cout << "La cle " << (*(p.first)).first << " existe deja" << endl;

	// rechercher une cl� d�j� pr�sente
	PersonneMap::iterator i = m.find(12);

	// supprimer l'objet correspondant � cette cl�
	if (i != m.end()) {
		m.erase(i);
		afficher(m);
	}
	else {
		cout << "La cle recherchee n'a pas ete trouvee" << endl;
	}

	// afficher les objets dans l'ordre croissant des cl�s
	cout << "Dans l'ordre croissant:" << endl;
	for (PersonneMap::reverse_iterator j = m.rbegin();j != m.rend(); ++j) {
		cout << (*j).first << '\t' << (*j).second.nom << ' ' << (*j).second.age << endl;
	}

	// afficher les objets dans l'ordre d�croissant des cl�s
	cout << "Dans l'ordre decroissant:" << endl;
	
	afficher(m);

	// modifier l'age d'un �l�ment de la map en utilisant sa cl� (notation [])
	m[61].age = 10;

	// afficher ensuite la map
	afficher(m);
}
