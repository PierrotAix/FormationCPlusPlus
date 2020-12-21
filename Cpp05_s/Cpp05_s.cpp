// Cpp05_s.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
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

	void init() {
		count = 0;
	}

	void init(int val) {
		count = val;
	}

	void init(Counter c) {
		count = c.lirecount();
		//count=c.count;
		//init(c.count);
	}
};

int main()
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

	return 0;
}
