// STL_Conteneur03.cpp�: d�finit le point d'entr�e pour l'application console.
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
	// d�finir une map m d'objets Personne avec cl� de comparaison greater


	// ins�rer 4 objets Personne


	// intercepter une tentative d'insertion d'une valeur 
	// d�j� pr�sente (cl� d�j� utilis�e)


	// rechercher une cl� d�j� pr�sente


	// supprimer l'objet correspondant � cette cl�


	// afficher les objets dans l'ordre croissant des cl�s


	// afficher les objets dans l'ordre d�croissant des cl�s


	// modifier l'age d'un �l�ment de la map en utilisant sa cl� (notation [])


	// afficher ensuite la map

}



