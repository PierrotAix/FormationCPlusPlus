// Cpp09_s.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "counter.h"

using namespace std;

int main()
{
	{
		Counter c1;
		c1.increment();
		c1.affiche();
		Counter c2;
		c2.affiche();
		int x = c1.lirecount();
		cout << "x: " << x << endl;

		c1.init();
		c1.affiche();
		c2.init(50);
		c2.affiche();
		c1.init(c2);
		c1.affiche();
		Counter c3(100);  // appel du constructeur Counter(int)
		c3.affiche();
		Counter c4(25L);  // appel du constructeur Counter(long)
		c4.affiche();
	}
	return 0;
}
