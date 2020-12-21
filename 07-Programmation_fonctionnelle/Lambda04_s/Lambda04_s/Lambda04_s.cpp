// Lambda04_s.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>

using namespace std;

/** permet de detecter si la chaine @p str est un palindrome.
* seuls les lettres, sans caractere espace, sont prises en compte
*/
bool is_palindrome(string str)
{
	// Filtre la chaine pour ne garder que les lettres
	string::iterator end{ remove_if(str.begin(), str.end(),
		[](char ch){
			return !isalpha(ch, locale());
		})
	};

	// la chaine est inversee
	string rev{ str.begin(), end };
	reverse(rev.begin(), rev.end());

	// la chaine initiale est comparee à celle inversee, en ignorant la casse
	return !rev.empty() && equal(str.begin(), end, rev.begin(),
		[](char a, char b){
			auto lowercase = [](char ch){ return tolower(ch, locale()); }; // lambda dans lambda
			return lowercase(a) == lowercase(b);
		}
	);
}

int main()
{
	locale::global(locale{});
	cin.imbue(locale{});
	cout.imbue(locale{});

	string line{};
	cout << "saisir une chaine:";
	while (getline(cin, line)) {
		if (is_palindrome(line)) {
			cout << line << " est un palindrome" << endl;
		}
		else {
			cout << line << " n'est pas un palindrome" << endl;
		}
		cout << "saisir une chaine:";
	}
	return 0;
}
