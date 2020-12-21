#include <iostream>

class Compteur{
	int cpt;
public:
	Compteur();
	Compteur(int a);
	void increment();
	bool operator< (const Compteur&) const;
	bool operator> (const Compteur&) const;
	int getCpt() const;
	void affiche() const;
	friend std::ostream& operator<< (std::ostream& os, const Compteur& c);
};
