// Pattern01_s.cpp�: d�finit le point d'entr�e pour l'application console.
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
