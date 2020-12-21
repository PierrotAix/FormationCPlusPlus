// Lambda05_s.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
	unique_ptr<FILE, void(*)(FILE*)> fic(fopen("main.cpp", "r"),
		[](FILE* fic)
		{
			cout << "fclose" << endl;
			fclose(fic);
		});

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

	//l'appel � fclose() est inutile car le pointeur unique_ptr s'en occupe

	return 0;
}

