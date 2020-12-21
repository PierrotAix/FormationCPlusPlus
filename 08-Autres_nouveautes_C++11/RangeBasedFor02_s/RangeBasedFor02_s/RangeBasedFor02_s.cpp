// RangeBasedFor02_s.cpp�: d�finit le point d'entr�e pour l'application console.
// https://oopscenities.net/2011/06/09/c0x-range-based-for-loop/

#include "stdafx.h"
#include <vector>
#include <array>
#include <iostream>

using namespace std;

/* la classe Range doit poss�der les m�thodes begin() et end() qui retourne un it�rateur
un it�rateur est une classe qui impl�mente un operator++(), un operator!=() et un operator*() pour 
respectivement acc�der � l'�lement suivant, pour v�rifier s'il y a d'autres �l�ments, et pour 
retourner l�l�ment courant
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

