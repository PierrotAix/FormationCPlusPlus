// Forward01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <iostream>

using namespace std;

struct X
{
	X()  { cout << "constructeur" << endl; } 
	X(const X&) { cout << "constructeur de copie" << endl; }
	X(X&&)   { cout << "constructeur par deplacement" << endl; }
};

struct Wrapper
{
	X w;
	Wrapper( X&& w): w(w)   { }
	Wrapper(const X& w) : w(w) { }
};

int main()
{
	Wrapper w1(X{});
	cout << "***" << endl;

	X y;
	Wrapper w2(y);

	return 0;
}