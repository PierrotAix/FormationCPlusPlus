// Lambda05.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <memory>

using namespace std;
/*
void fermeture(FILE* fic) {
	cout << "fclose" << endl;
	fclose(fic);
}
*/

auto fermeture = [&](FILE* fic) -> void { fclose(fic); }; // COMPLETER

int main()
{
	unique_ptr<FILE, void(*)(FILE*)> fic(fopen("main.cpp", "r"), /*&fermeture*/ fermeture);

	if (fic != nullptr) {
		char aux[100];
		while (!feof(fic.get())) //f.get retourne le pointeur nu 
		{
			fgets(aux, 100, fic.get());
			cout << aux;
		}
	}else {
		cerr << "ouverture du fichier impossible !" << endl;
	}

	//l'appel à fclose() est inutile car le custom deleter de unique_ptr 
	// s'en occupe

	return 0;
}



