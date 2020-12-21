// Lambda02_s.cpp : définit le point d'entrée pour l'application console.
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

		// passer une lambda en dernier argument pour afficher les éléments du vector v
		for_each(v.begin(), v.end(), [](int v) {cout << setfill('.') << setw(8) << hex << v << '\n';});
	}
	else {
		cerr << "fichier non trouve !" << endl;
	}
	return 0;

}
