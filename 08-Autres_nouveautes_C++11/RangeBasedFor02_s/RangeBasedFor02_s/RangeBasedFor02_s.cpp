// RangeBasedFor02_s.cpp : définit le point d'entrée pour l'application console.
// https://oopscenities.net/2011/06/09/c0x-range-based-for-loop/

#include "stdafx.h"
#include <vector>
#include <array>
#include <iostream>

using namespace std;

/* la classe Range doit posséder les méthodes begin() et end() qui retourne un itérateur
un itérateur est une classe qui implémente un operator++(), un operator!=() et un operator*() pour 
respectivement accéder à l'élement suivant, pour vérifier s'il y a d'autres éléments, et pour 
retourner lélément courant
*/

class RangeIterator
{
private:
	int _index;

public:
	RangeIterator(int index) : _index(index) { }

	bool operator!=(const RangeIterator& x) const
	{
		return _index != x._index + 1;
	}

	const int& operator*() const
	{
		return _index;
	}

	int operator++()
	{
		return ++_index;
	}
};

template <int N, int M>
class Range
{
public:
	typedef const RangeIterator const_iterator;

	const_iterator begin() const
	{
		return const_iterator(N);
	}

	const_iterator end() const
	{
		return const_iterator(M);
	}
};

template <typename T>
void show(const T& t)
{
	for (auto& i : t) {
		cout << i << endl;
	}
}


int main()
{
	Range<10, 20> r;
	show(r);

	return 0;
}

