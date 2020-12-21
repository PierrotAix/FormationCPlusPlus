// Cpp04_s.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

using namespace std;

class Counter
{
private:
	int count;

public:
	void increment() {
		count++;
	}
	void affiche() {
		cout << "valeur: " << count << endl;
	}
	int lirecount() {
		return count;
	}
};

int main()
{
	Counter c1;
	c1.increment();
	c1.affiche();

	Counter c2;
	c2.affiche();
	//c2.count= 0;
	int x = c1.lirecount();
	cout << "x: " << x << endl;

	return 0;
}
