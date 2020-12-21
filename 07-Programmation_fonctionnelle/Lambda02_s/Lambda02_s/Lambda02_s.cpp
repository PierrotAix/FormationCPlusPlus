// Lambda02_s.cpp�: d�finit le point d'entr�e pour l'application console.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

	
	vector<int> v;
	ifstream ifs("valeurs.txt");
	
	if (ifs) {
		for (int val; ifs >> val; v.push_back(val));

		// passer une lambda en dernier argument pour afficher les �l�ments du vector v
		for_each(v.begin(), v.end(), [](int v) {cout << setfill('.') << setw(8) << hex << v << '\n';});
	}
	else {
		cerr << "fichier non trouve !" << endl;
	}
	return 0;

}
