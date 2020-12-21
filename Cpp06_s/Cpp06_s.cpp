// Cpp06_s.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

using namespace std;

class Counter
{
private:
	int count;

public:
	//Counter(){
	//    count=0;
	//} 
	Counter() : count(0) {}

	//Counter(int a){
	//    count=a;
	//} 
	Counter(int a) : count(a) { cout << "int" << endl; }

	//Counter(long b){
	//    count=static_cast<int>(b);
	//} 
	Counter(long b) : count(static_cast<int>(b)) { cout << "long" << endl; }


	void increment() {
		count++;
	}

	void affiche() {
		cout << "valeur: " << count << endl;
	}

	int lirecount() {
		return count;
	}

	void init() {
		count = 0;
	}
	void init(int val) {

		count = val;
	}
	void init(Counter c) {
		//count=c.lirecount();
		//init(c.count);
		cout << "Appel du constructeur par copie: " << endl;
		count = c.count;
	}
};

int main()
{
	Counter c1;
	c1.increment();
	c1.affiche();
	Counter c2;
	c2.affiche();
	int x = c1.lirecount();
	cout << "x: " << x << endl;

	c1.init();
	c1.affiche();
	c2.init(50);
	c2.affiche();
	c1.init(c2);
	c1.affiche();
	Counter c3(100);  // appel du constructeur Counter(int)
	c3.affiche();
	Counter c4(25L);  // appel du constructeur Counter(long)
	c4.affiche();

	return 0;
}
