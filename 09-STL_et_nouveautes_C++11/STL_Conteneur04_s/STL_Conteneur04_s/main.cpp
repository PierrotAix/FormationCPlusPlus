// STL_Conteneur04_s.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <queue>
#include <list>

using namespace std;

int main() {
	// cr�er une queue file1 de string r�alis�e � l'aide d'une liste
	queue<string, list<string> > file1;

	// cr�er une queue file2 par d�faut (r�alis�e � l'aide de deque)
	queue<string> file2;

	// placer 3 valeurs dans file1
	file1.push("le");
	file1.push("langage");
	file1.push("c++");

	// afficher la t�te et la queue de file1
	cout << "tete :" << file1.front() << endl
		<< "queue :" << file1.back() << endl;

	// vider file1 et remplir file2 avec les valeurs t�te de file1
	while (!file1.empty()) {
		file2.push(file1.front());
		file1.pop();
	}
	cout << "file1 est vide, sa taille vaut " << file1.size() << endl;

	// afficher file2
	while (!file2.empty()) {
		cout << file2.front() << endl;
		file2.pop();
	}

	return 0;
}
