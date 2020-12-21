// Pattern01_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <memory>
#include <iostream>
#include "SequenceGenerator.h"

using namespace std;

int main() {

	unique_ptr<SequenceGenerator> p(SequenceGenerator::getInstance());
	cout << p->getNombre() << endl;
	cout << p->getNombre() << endl;
	cout << p->getNombre() << endl;
	cout << p->getNombre() << endl;
	cout << p->getNombre() << endl;
	cout << p->getNombre() << endl;
	cout << p->getNombre() << endl;
	
	return 0;
}
