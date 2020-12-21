// Lambda03_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> data{ 1, 2, 3, 4, 5, 6 };

	int multiplieur{ 3 };
	auto mult = [&multiplieur](int i) { return i * multiplieur; }; // passage de multiplier par référence

	cout << "apres multiplication des elements par " << multiplieur << ": " ;
	transform(data.begin(), data.end(), data.begin(), mult);
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	multiplieur = 5;
	cout << "apres multiplication des elements par " << multiplieur << ": ";
	transform(data.begin(), data.end(), data.begin(), mult);

	copy(data.begin(), data.end(),ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
