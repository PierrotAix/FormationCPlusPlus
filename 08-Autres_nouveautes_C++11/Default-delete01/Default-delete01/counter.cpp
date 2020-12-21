#include "stdafx.h"
#include <iostream>
#include "counter.h"

using namespace std;

int Counter::nbcounter = 0;   // d�f. et init. de la variable de classe

int Counter::lirenbcounter() // m�thode de classe
{
	return nbcounter;
}
Counter::Counter()
{
	count = 0;
	nbcounter++;
}
Counter::Counter(int a)
{
	count = a;
	nbcounter++;
}
Counter::Counter(long b)
{
	count = static_cast<int>(b);
	nbcounter++;
}
Counter::~Counter()
{
	//cout<<"ex�cution du destructeur"<<endl;
}
Counter& Counter::increment()
{
	count++;
	return *this;
}
void Counter::affiche() const
{
	cout << "valeur: " << count << endl;
}
int Counter::lirecount() const
{
	return count;
}
void Counter::init(int val)
{
	count = val;
}
void Counter::init(const Counter& c)
{
	//count=c.lirecount();
	//init(c.count);
	count = c.count;
}
Counter& Counter::add(const Counter& c)
{
	count += c.count;
	return *this;
}
Counter::operator int() const
{
	return count;
}
Counter operator+(const Counter& c1, const Counter& c2) {
	Counter temp(c1);
	temp.add(c2);
	return temp;
}
Counter& operator+=(Counter& c1, const Counter& c2) {
	return c1.add(c2);
}
