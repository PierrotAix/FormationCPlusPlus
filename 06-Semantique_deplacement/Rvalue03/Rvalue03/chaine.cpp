
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "chaine.h"

using namespace std;

Chaine::Chaine()
{
	longueur = 0;
	pch = new char[1];
	*pch = '\0';
}
Chaine::Chaine(const char* s)
{
	longueur = strlen(s);
	pch = new char[longueur + 1];
	strcpy(pch, s);
}
Chaine::Chaine(const Chaine& c)
{
	cout << "======>   Chaine(const Chaine&)" << endl;
	longueur = c.longueur;
	pch = new char[longueur + 1];
	strcpy(pch, c.pch);
}
Chaine::~Chaine()
{
	delete[] pch;
}
Chaine& Chaine::copie(const char* s)
{
	delete[] pch;
	longueur = strlen(s);
	pch = new char[longueur + 1];
	strcpy(pch, s);
	return *this;
}
Chaine& Chaine::copie(const Chaine& c)
{
	if (this != &c)
	{
		delete[] pch;
		longueur = c.longueur;
		pch = new char[longueur + 1];
		strcpy(pch, c.pch);
	}
	return *this;
}
Chaine& Chaine::concat(const char* s)
{
	longueur += strlen(s);
	char* temp = new char[longueur + 1];
	strcpy(temp, pch);
	strcat(temp, s);
	delete[] pch;
	pch = temp;
	return*this;
}
Chaine& Chaine::concat(const Chaine& c)
{
	longueur += c.longueur;
	char* temp = new char[longueur + 1];
	strcpy(temp, pch);
	strcat(temp, c.pch);
	delete[] pch;
	pch = temp;
	return*this;
}
int Chaine::compare(const char* s) const
{
	return strcmp(pch, s);
}
int Chaine::length() const
{
	return longueur;
}
void Chaine::print() const
{
	cout << pch << endl;
}
Chaine& Chaine::operator=(const Chaine& c){
	cout << "======>   operator=(const Chaine& c)" << endl;
	if (this != &c) {
		delete[] pch;
		longueur = c.longueur;
		pch = new char[longueur + 1];
		strcpy(pch, c.pch);
	}
	return *this;
}

Chaine& Chaine::operator=(const &&other) noexcept {
	cout << "======>   operator=(const Chaine& c)" << endl;
	if (this != &c) {
		delete[] pch;
		longueur = c.longueur;
		pch = new char[longueur + 1];
		strcpy(pch, c.pch);
	}
	return *this;
}


Chaine& Chaine::operator+=(const char* s)
{
	return concat(s);
}
char& Chaine::operator[](int i)
{
	if (i<0 || i >= longueur)
		cerr << "indice erroné" << endl;
	else return *(pch + i);
}
Chaine operator+(const Chaine& c1, const Chaine& c2)
{
	Chaine temp = c1;
	temp.concat(c2);
	return temp;
}
Chaine::operator const char* () const
{
	return pch;
}
ostream& operator<< (ostream& os, const Chaine& c)
{
	if (c.pch != nullptr) {
		os << c.pch;
	}
	return os;
}

