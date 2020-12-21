// Thread01_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

struct Rebours
{
	int m_secs;

	Rebours(int secs) : m_secs(secs) { }

	void operator()() {
		do {
			cout << m_secs << std::endl;
			this_thread::sleep_for(chrono::seconds(1));
			m_secs--;
		} while (m_secs>0);
		cout << "Fin du compte a rebours..." << endl;
	}

	void calcul() { this->operator()(); }
};

int main() {
	int secs = 5;
	cout << "Compte a rebours lance..." << endl;
	Rebours rebours(secs);
	thread thrd(rebours);
	thrd.join();
	
	thread thrd2(&Rebours::calcul, rebours);// exemple de thread sur méthode
	thrd2.join();
	
	return 0;
}

/*
int main() {
	int secs = 5;
	std::cout << "Compte a rebours lance..." << std::endl;
	thread thrd([secs]() {
		auto m_secs = secs;
		do {
			cout << m_secs << endl;
			this_thread::sleep_for(chrono::seconds(1));
			m_secs--;
		} while (m_secs>0);
		cout << "Fin du compte a rebours..." << endl;
	});
	thrd.join();

	return 0;
}
*/

