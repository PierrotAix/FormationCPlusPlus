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
		// Test du fichier
				// get length of file:
		ifs.seekg(0, ifs.end);
		int length = ifs.tellg();
		ifs.seekg(0, ifs.beg);

		char* buffer = new char[length];

		cout << "Reading " << length << " characters... ";
		// read data as a block:
		ifs.read(buffer, length);

		if (ifs)
			cout << "all characters read successfully.";
		else
			cout << "error: only " << ifs.gcount() << " could be read";
		ifs.close();

		// ...buffer contains the entire file...

		delete[] buffer;


 		for (int val; ifs >> val; v.push_back(val));

		// passer une lambda en dernier argument pour afficher les éléments du vector v
		for_each(v.begin(), v.end(), [](int v) {cout << setfill('.') << setw(8) << hex << v << '\n';});
	}
	else {
		cerr << "fichier non trouve !" << endl;
	}
	return 0;

}
