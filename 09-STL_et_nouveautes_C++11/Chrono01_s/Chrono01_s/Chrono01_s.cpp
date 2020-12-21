// Chrono01_s.cpp : définit le point d'entrée pour l'application console.


#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

bool bissextile(int annee)
{
	if (annee % 400 == 0)
		return true;
	if (annee % 100 == 0)
		return false;
	if (annee % 4 == 0)
		return true;
	return false;
}

int main()
{
	std::tm t = {};
	int annee_courante;
	int jour;
	int mois;
	char date[16];

	time_t today = time(NULL);
	t = *localtime(&today);
	annee_courante = t.tm_year + 1900;

	cout << "jour mois de votre anniversaire:";
	cin >> jour >> mois;
	sprintf(date, "%04d-%02d-%02d",annee_courante, mois, jour);
	
	//cout << "date: " << date << endl;
	std::istringstream ss(date);
	ss.imbue(std::locale("fr_FR.UTF-8"));
	ss >> std::get_time(&t, "%Y-%m-%d");
	if (ss.fail()) {
		std::cout << "format de date non reconnu" << endl;
		return 0;
	}
	//else {
	//	std::cout << std::put_time(&t, "%d / %m / %Y") << endl;
	//}
	auto tp_anniv = std::chrono::system_clock::from_time_t(std::mktime(&t));
	auto tp_aujourdhui = std::chrono::system_clock::now();
	auto jours = (std::chrono::duration_cast<std::chrono::hours>(tp_anniv - tp_aujourdhui).count()) / 24;
	if (jours < 0) {
		if(bissextile(annee_courante)){
			jours = 365 + jours;
		}	
	}
	std::cout << "il reste " << jours << " jours avant mon prochain anniversaire" << endl;
    return 0;
}

