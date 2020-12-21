// IntialisationUniforme01_s.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
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
private:
	int alpha;
	double beta;

public:
	B(int x, double y) : alpha{ x }, beta{ y } {
		std::cout << "B: constructeur avec deux arguments" << std::endl;
	}
	
	void affiche() {
		std::cout << alpha << " " << beta << std::endl;
	}
};


class C
{
private:
	int alpha;
	double beta;

public:
	C(const std::initializer_list<double>& v) {
		std::cout << "C: constructeur avec initializer_list" << std::endl;
		alpha = static_cast<int>(*(v.begin()));
		beta = *(v.begin() + 1);
	}

	void affiche() {
		std::cout << alpha << " " << beta << std::endl;
	}
};

int main()
{
	// initialiation par aggrégat
	A a { 1, 3.7 };
	a.affiche();

	// constructeur ordinaire
	B b { 2, 9.8 };
	b.affiche();

	// constructeur avec initializer_list
	C c { 3, 7.8 };
	c.affiche();

	return 0;
}
