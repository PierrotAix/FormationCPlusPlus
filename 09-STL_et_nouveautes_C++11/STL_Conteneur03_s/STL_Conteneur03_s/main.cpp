// STL_Conteneur03_s.cpp : définit le point d'entrée pour l'application console.
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

	// va les afficher dans l'ordre decroissant à cause de greater
	for (i = s.begin(); i != s.end(); ++i) {
		cout << (*i).first << '\t' << (*i).second.nom
			<< ' ' << (*i).second.age << endl;
	}
	cout << "La map contient " << s.size() << " elements" << endl;
}

int main() {
	// définir une map m d'objets Personne avec clé de comparaison greater
	PersonneMap m;

	// insérer 4 objets Personne
	m.insert(valeurPersonneMap(12, Personne(38, "Nino")));
	m.insert(valeurPersonneMap(214, Personne(10, "Julien")));
	m.insert(valeurPersonneMap(61, Personne(9, "Laurent")));
	m.insert(valeurPersonneMap(1, Personne(3, "Lina")));

	// intercepter une tentative d'insertion d'une valeur déjà présente (clé déjà utilisée)
	pair<PersonneMap::iterator, bool> p
		= m.insert(valeurPersonneMap(1, Personne(37, "Dominique")));
	if (!p.second)
		cout << "La cle " << (*(p.first)).first << " existe deja" << endl;

	// rechercher une clé déjà présente
	PersonneMap::iterator i = m.find(12);

	// supprimer l'objet correspondant à cette clé
	if (i != m.end()) {
		m.erase(i);
		afficher(m);
	}
	else {
		cout << "La cle recherchee n'a pas ete trouvee" << endl;
	}

	// afficher les objets dans l'ordre croissant des clés
	cout << "Dans l'ordre croissant:" << endl;
	for (PersonneMap::reverse_iterator j = m.rbegin();j != m.rend(); ++j) {
		cout << (*j).first << '\t' << (*j).second.nom << ' ' << (*j).second.age << endl;
	}

	// afficher les objets dans l'ordre décroissant des clés
	cout << "Dans l'ordre decroissant:" << endl;
	
	afficher(m);

	// modifier l'age d'un élément de la map en utilisant sa clé (notation [])
	m[61].age = 10;

	// afficher ensuite la map
	afficher(m);
}
