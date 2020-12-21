// RangeBasedFor02.cpp : définit le point d'entrée pour l'application console.
//

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

