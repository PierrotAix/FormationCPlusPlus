// InitialisationUniforme01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>

class A
{
public:
	int alpha;
	double beta;

	void affiche() {
		std::cout << alpha << " " << beta << std::endl;
	}
};

class B
{
public:
	int alpha;
	double beta;

	void affiche() {
		std::cout << alpha << " " << beta << std::endl;
	}
};

class C
{
public:
	int alpha;
	double beta;

	void affiche() {
		std::cout << alpha << " " << beta << std::endl;
	}
};


int main()
{
	// initialiation par aggrégat
	A a{ 1, 3.7 };
	a.affiche();

	
	// constructeur ordinaire
	B b{ 2, 9.8 };
	b.affiche();


	// constructeur avec initializer_list
	C c{ 3, 7.8 };
	c.affiche();

	return 0;
}
