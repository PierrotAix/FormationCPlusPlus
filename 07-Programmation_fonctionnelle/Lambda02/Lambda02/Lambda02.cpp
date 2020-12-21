// Lambda02.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

template <typename T>
class afficher {
	ostream &os;
public:
	//afficher(std::ostream &os) : os(os) {}

	//afficher [&](ostream& os) { std::cout << &os << endl; }

	void operator()(const T &val) {
		os << setfill('.') << setw(8) << hex << val << '\n';
	}
};


int main() {

	vector<int> v;
	ifstream ifs("valeurs.txt");
	if (ifs) {
		for (int val; ifs >> val; v.push_back(val));

		for_each(v.begin(), v.end(), [&](ostream& os) { std::cout << &os << endl; });
	
	}else {
		cerr << "fichier non trouve !" << endl;
	}
	return 0;
}
