// STL_Conteneur03.cpp : définit le point d'entrée pour l'application console.
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


int main() {
	// définir une map m d'objets Personne avec clé de comparaison greater


	// insérer 4 objets Personne


	// intercepter une tentative d'insertion d'une valeur 
	// déjà présente (clé déjà utilisée)


	// rechercher une clé déjà présente


	// supprimer l'objet correspondant à cette clé


	// afficher les objets dans l'ordre croissant des clés


	// afficher les objets dans l'ordre décroissant des clés


	// modifier l'age d'un élément de la map en utilisant sa clé (notation [])


	// afficher ensuite la map

}



