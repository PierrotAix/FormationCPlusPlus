// Lambda04.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>

using namespace std;

/** permet de detecter si la chaine str est un palindrome.
* seuls les lettres, sans caractere espace, sont prises en compte
*/
bool is_palindrome(string str)
{
	// Filtre la chaine pour ne garder que les lettres
	string::iterator end{ remove_if(str.begin(), str.end(),

		// COMPLETER (utiliser isalpha)

	};

	// la chaine est inversee
	string rev{ str.begin(), end };
	reverse(rev.begin(), rev.end());

	// la chaine initiale est comparee à celle inversee, en ignorant la casse
	return !rev.empty() && equal(str.begin(), end, rev.begin(),

		// COMPLETER (utiliser tolower)

		);
}

int main()
{
	locale::global(locale{ "" });
	cin.imbue(locale{});
	cout.imbue(locale{});

	string line{};
	cout << "saisir une chaine:";
	while (getline(cin, line)) {
		if (is_palindrome(line)) {
			cout << line << " est un palindrome" << endl;
		}else {
			cout << line << " n'est pas un palindrome" << endl;
		}
		cout << "saisir une chaine:";
	}
	return 0;
}



