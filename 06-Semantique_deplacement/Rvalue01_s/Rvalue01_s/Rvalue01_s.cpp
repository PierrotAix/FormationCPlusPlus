// Rvalue01_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "chaine.h"

using namespace std;

//#define CHAINE
#ifndef CHAINE

void print(string&& mv)
{
	cout << "print(string&&): " << mv << '\n';
}

void print(const string& cp)
{
	cout << "print(const string&): : " << cp << '\n';
}


int main()
{
	string a{ "a" }, b{ "b" }, c{ "c" };

	print(a);					// a 		print(const string&)
	print(a + b);				// ab 		print(string&&)
	print(std::move(a));		// a 		print(string&&)	
	print(std::move(a + b));	// ab 		print(string&&)
	print(a + std::move(b));	// ab		print(string&&)
	print(a + b + c);			// ac		print(string&&)
	
	return 0;
}

#else

void print(Chaine&& mv)
{
	cout << "	methode print(string&&): " << mv << '\n';
}


void print(const Chaine& cp)
{
	cout << "	methode print(const string&): : " << cp << '\n';
}

int main()
{	
	Chaine a{ "a" };
	Chaine b{ "b" };
	Chaine c{ "c" };

	cout << "\nprint(a); " << endl;
	print(a);								// a		print(const string&)
	
	cout << "\nprint(a + b); " << endl;
	print(a + b);							// ab		print(string&&)
	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

	cout << "\nprint(std::move(a));  " << endl;
	print(std::move(a));					// a		print(string&&)
	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

	cout << "\nprint(std::move(a + b));  " << endl;
	print(std::move(a + b));				// ab		print(string&&)
	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

	cout << "\nprint(a + std::move(b)); " << endl;
	print(a + std::move(b));				// ab		print(string&&) et b est vidé
	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

	cout << "\nprint(a + b + c); " << endl;
	print(a + b + c);						// ac		print(string&&)
	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
	
	return 0;
}

#endif // !CHAINE

