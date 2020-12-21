// appli.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <new>
#include "chaine.h"

using namespace std;

void erreur_alloc()
{
	cerr << "allocation impossible!" << endl;
	exit(1);
}

int main()
{
	set_new_handler(erreur_alloc);

	Chaine s1;
	s1.print();
	Chaine s2("Au revoir !");
	s2.print();
	s1.copie("Bonjour ");
	s1.print();
	s1.concat("tout le Monde!");
	s1.print();
	cout << "longueur de la chaine s1: " << s1.length() << endl;
	if (s2.compare("Au revoir !") == 0) cout << "chaines identiques" << endl;
	else cout << "chaines differentes" << endl;
	Chaine s3("Bla..Bla");
	s3.copie(s1).print();
	s3.concat(s2).print();

	{
		Chaine s4(s3);
		s3.copie("bye...");
		s4 = s3;
		s4.copie("hello...");
		s3.print(); // doit afficher "bye..."
		s4.print(); // doit afficher "hello..."

		s4 += "cow are you?";
		s4.print();

		int pos = 8;
		char c = s4[pos];
		cout << "caractere en position " << pos << ": " << c << endl;
		s4[pos] = 'h';
		s4.print();

		cout << "=======================================================================" << endl;
		Chaine s5("qui fait deborder le vase");
		Chaine s6 = "c'est la goutte d'eau " + s5;
		s6.print();

		const char* t = s6;
		cout << "chaine t: " << t << endl;

		cout << s4 << endl;

		cout << "=======================================================================" <<endl;
		Chaine s7{ move(s4) }; // appel du constructeur par déplacement
		cout << "s7= " <<s7<< endl;
		cout << "s4= " << s4 << endl;

		cout << "s7 = Chaine(\"beta\"): ";
		s7 = Chaine("beta");
		cout << s7 << endl;

		cout << "s4 = std::move(s7): ";
		s4 = move(s7); // appel de l'opérateur =  par déplacement
		cout << "s4= " << s4 << endl;
		cout << "s7= " << s7 << endl;
	}

	return 0;
}
