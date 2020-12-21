// STL_Conteneur02_s.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

typedef list<string>          StringListe;
typedef StringListe::iterator StringListeIt;

void affiche_element(StringListe::value_type v) {
	cout << v << ' ';
}

void affiche(string s, const StringListeIt& deb, const StringListeIt& fin) {
	cout << s;
	for_each(deb, fin, affiche_element);
	cout << endl;
}

int main() {
	// cr�er une liste l1
	StringListe l1;

	// ins�rer deux cha�nes en t�te de liste
	l1.push_front("Bjarne");
	l1.push_front("Stroustrup");

	// ins�rer deux cha�nes en fin de liste
	l1.push_back("C++");
	l1.push_back("STL");

	// afficher le contenu de la liste avec for_each
	affiche("L1 : ", l1.begin(), l1.end());

	// afficher l'�l�ment en t�te
	cout << l1.front() << endl;

	// afficher l'�l�ment en queue
	cout << l1.back() << endl;

	// supprimer l'�l�ment en t�te
	l1.pop_front();

	// supprimer l'�l�ment en queue
	l1.pop_back();

	// trier la liste
	l1.sort();

	// afficher le contenu de la liste avec un it�rateur
	for (StringListeIt i = l1.begin(); i != l1.end(); ++i)
		cout << *i << ' ';
	cout << endl;

	// cr�er une liste l2
	StringListe l2;

	// inserer six cha�nes en tete de liste l2
	l2.push_front("Classe");   l2.push_front("Objet");
	l2.push_front("Silverio"); l2.push_front("Heritage");
	l2.push_front("Bjarne");   l2.push_front("Stroustrup");

	// trier la liste l2
	l2.sort();

	// afficher le contenu de la liste l2
	affiche("L2 : ", l2.begin(), l2.end());

	// faire un merge de l1 dans l2
	l2.merge(l1);

	// afficher le contenu de la liste l2
	affiche("L2 apres fusion : ", l2.begin(), l2.end());

	// supprimer les doulons dans l2
	l2.unique();

	// afficher le contenu de la liste l2
	affiche("L2 apres unique : ", l2.begin(), l2.end());

	// inverser le contenu de la liste l2
	l2.reverse();

	// afficher le contenu de la liste l2
	affiche("L2 apres reverse : ", l2.begin(), l2.end());

	// supprimer une cha�ne de l2
	l2.remove("Silverio");

	// afficher le contenu de la liste l2
	affiche("L2 apres remove : ", l2.begin(), l2.end());

	// ins�rer deux cha�nes en t�te de liste l1
	l1.push_front("Pascal");    l1.push_front("Modula");

	// afficher le contenu de la liste l1
	affiche("L1 : ", l1.begin(), l1.end());

	// inserer (avec splice) la liste l2 dans la liste l1 entre le premier et le deuxi�me �l�ment
	l1.splice(++(l1.begin()), l2);

	// afficher le contenu de la liste l1
	affiche("L1 apres splice : ", l1.begin(), l1.end());

	// afficher le contenu de la liste l2
	affiche("L2 apres splice : ", l2.begin(), l2.end());

}
