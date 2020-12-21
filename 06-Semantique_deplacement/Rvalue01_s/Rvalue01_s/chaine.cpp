#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "chaine.h"

using namespace std;

//http://fr.cppreference.com/w/cpp/string/basic_string/operator%2B

/*
(1)
template< class CharT, class Traits, class Alloc >
basic_string<CharT, Traits, Alloc>
operator+(const basic_string<CharT, Traits, Alloc>& lhs,
	const basic_string<CharT, Traits, Alloc>& rhs);

(6) 	(depuis C++11)
template< class CharT, class Traits, class Alloc >
basic_string<CharT, Traits, Alloc>
operator+(basic_string<CharT, Traits, Alloc>&& lhs,
	const basic_string<CharT, Traits, Alloc>& rhs);

(7) 	(depuis C++11)
template< class CharT, class Traits, class Alloc >
basic_string<CharT, Traits, Alloc>
operator+(const basic_string<CharT, Traits, Alloc>& lhs,
	basic_string<CharT, Traits, Alloc>&& rhs);


(8) 	(depuis C++11)
template< class CharT, class Traits, class Alloc >
basic_string<CharT, Traits, Alloc>
operator+(basic_string<CharT, Traits, Alloc>&& lhs,
	basic_string<CharT, Traits, Alloc>&& rhs);



Paramètres
lhs - string, character, ou un pointeur vers le premier caractère dans un tableau terminé par NULL

rhs - string, character, ou un pointeur vers le premier caractère dans un tableau terminé par NULL

Retourne la valeur

1) basic_string<CharT, Traits, Alloc>(lhs).append(rhs)

2) basic_string<CharT, Traits, Alloc>(lhs) + rhs

3) basic_string<CharT, Traits, Alloc>(1, lhs) + rhs

4) lhs + basic_string<CharT, Traits, Alloc>(rhs)

5) lhs + basic_string<CharT, Traits, Alloc>(1, rhs)

6) std::move(lhs.append(rhs))

7) std::move(rhs.insert(0, lhs))

8) std::move(lhs.append(rhs)) or std::move(rhs.insert(0, lhs))

9) std::move(rhs.insert(0, lhs))

10) std::move(rhs.insert(0, 1, lhs))

11) std::move(lhs.append(rhs))

12) std::move(lhs.append(1, rhs))
*/


Chaine::Chaine()
{
	cout << "======>   Chaine()" <<endl;
	longueur = 0;
	pch = new char[1];
	*pch = '\0';
}
Chaine::Chaine(const char* s)
{
	cout << "======>   Chaine(const char*): " << s <<endl;
	longueur = strlen(s);
	pch = new char[longueur + 1];
	strcpy(pch, s);
}
Chaine::Chaine(const Chaine& c)
{
	cout << "======>   Chaine(const Chaine&): " << ((c.pch == nullptr) ? "nullptr" : c.pch) << endl;
	if (c.pch != nullptr) {
		longueur = c.longueur;
		pch = new char[longueur + 1];
		strcpy(pch, c.pch);
	}else {
		pch = nullptr;
		longueur = 0;
	}
}
Chaine::Chaine(Chaine&& c) {
	cout << "======>   Chaine(Chaine&&): " << ((c.pch == nullptr) ? "nullptr" : c.pch) << endl;
	longueur = c.longueur;
	pch = c.pch;
	c.longueur = 0;
	c.pch = nullptr;
}
Chaine::~Chaine()
{
	if (pch != nullptr) {
		delete[] pch;
	}
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
	return *this;
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
Chaine& Chaine::operator=(Chaine&& c) {
	cout << "======>   operator=(Chaine&& c)" << endl;
	if (this != &c) {
		delete[] pch;
		longueur = c.longueur;
		pch = c.pch;
		c.longueur = 0;
		c.pch = nullptr;
	}
	return *this;
}
Chaine& Chaine::operator+=(const char* s)
{
	return concat(s);
}
char& Chaine::operator[](int i)
{
	static char temp;
	if (i < 0 || i >= longueur) {
		cerr << "indice erroné" << endl;
		return temp;
	} else {
		return *(pch + i);
	}
}
Chaine operator+(const Chaine& lhs, const Chaine& rhs) // idem (1) de std:string ---> retourne basic_string<CharT, Traits, Alloc>(lhs).append(rhs)
{
	cout << "======>   operator+(const Chaine&, const Chaine&)" << endl;
	Chaine temp1 = lhs;
	if (temp1.pch == nullptr) {
		temp1.pch = new char[1];
		*temp1.pch = '\0';
		temp1.longueur = 0;
	}
	Chaine temp2 = rhs;
	if (temp2.pch == nullptr) {
		temp2.pch = new char[1];
		*temp2.pch = '\0';
		temp2.longueur = 0;
	}
	temp1.concat(temp2);
	return temp1;
}
Chaine operator+(Chaine&& lhs, const Chaine& rhs)		// idem (6) de std:string ---> retourne std::move(lhs.append(rhs))
{
	cout << "======>   operator+(Chaine&&, const Chaine&)" << endl;
	if (lhs.pch == nullptr) {
		lhs.pch = new char[1];
		*lhs.pch = '\0';
		lhs.longueur = 0;
	}
	lhs.longueur += rhs.longueur;
	char* temp = new char[lhs.longueur + 1];
	strcpy(temp, lhs.pch);
	strcat(temp, rhs.pch);
	delete[] lhs.pch;
	lhs.pch = temp;
	return std::move(lhs);
}
Chaine operator+(const Chaine& lhs, Chaine&& rhs)		// idem (7) de std:string ---> retourne std::move(rhs.insert(0, lhs))
{
	cout << "======>   operator+(const Chaine&, Chaine&&)" << endl;
	if (rhs.pch == nullptr) {
		rhs.pch = new char[1];
		*rhs.pch = '\0';
		rhs.longueur = 0;
	}
	rhs.longueur += lhs.longueur;
	char* temp = new char[rhs.longueur + 1];
	strcpy(temp, lhs.pch);
	strcat(temp, rhs.pch);
	delete[] rhs.pch;
	rhs.pch = temp;
	return std::move(rhs);
}
Chaine operator+(Chaine&& lhs, Chaine&& rhs)			// idem (8) de std:string ---> retourne std::move(lhs.append(rhs)) ou std::move(rhs.insert(0, lhs))
{
	cout << "======>   operator+(Chaine&&, Chaine&&)" << endl;
	if (lhs.pch == nullptr) {
		lhs.pch = new char[1];
		*lhs.pch = '\0';
		lhs.longueur = 0;
	}
	lhs.longueur += rhs.longueur;
	char* temp = new char[lhs.longueur + 1];
	strcpy(temp, lhs.pch);
	strcat(temp, rhs.pch);
	delete[] lhs.pch;
	lhs.pch = temp;
	return std::move(lhs);
}
Chaine::operator const char* () const
{
	return pch;
}
ostream& operator<< (ostream& os, const Chaine& c)
{
	os << ((c.pch == nullptr) ? "nullptr" : c.pch);
	return os;
}

