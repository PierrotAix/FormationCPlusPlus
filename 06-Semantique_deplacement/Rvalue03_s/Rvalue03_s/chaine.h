#include <iostream>
using namespace std;

class Chaine {
	char *pch;
	int longueur;
public:
	Chaine();
	Chaine(const char*);
	Chaine(const Chaine&);	// constructeur de copie
	Chaine(Chaine&&);		// constructeur par déplacement
	~Chaine();
	Chaine& operator=(const Chaine&);	// operateur d'affectation par copie
	Chaine& operator=(Chaine&&);		// operateur d'affectation par déplacement
	Chaine& copie(const char*);
	Chaine& copie(const Chaine&);
	Chaine& concat(const char*);
	Chaine& concat(const Chaine&);
	int compare(const char*) const;
	int length() const;
	void print() const;
	Chaine& operator+=(const char*);
	char& operator[](int);
	friend Chaine operator+(const Chaine&, const Chaine&);
	operator const char* () const ;
	friend ostream& operator<< (ostream&, const Chaine&);
};
