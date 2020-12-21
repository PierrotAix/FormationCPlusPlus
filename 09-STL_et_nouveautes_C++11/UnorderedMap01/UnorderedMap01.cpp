// UnorderedMap01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <unordered_map>

using namespace std;

template<char delimiter>
class SplitChaine : public std::string
{};

template<char delimiter>
std::istream& operator>>(std::istream& is, SplitChaine<delimiter>& output)
{
    std::getline(is, output, delimiter);
    return is;
}

int main()
{
    string numero;
    string ligne;
    unordered_map<string, string> umap;

    auto deleter = [](ifstream* p) {
        cout << "fermeture fichier" << endl;
        p->close();
    };
    auto pfichier = std::unique_ptr<ifstream, decltype(deleter)>(new ifstream("code_postaux.txt"), deleter);

    if (*pfichier)
    {
        while (getline(*pfichier, ligne))
        {
            std::istringstream iss(ligne);
            std::vector<std::string> commune(
                // COMPLETER ICI par 2 arguments de type std::istream_iterator<SplitChaine>
            );
            cout << commune[1] << " " << commune[0] << endl;

            // COMPLETER : ajouter la commune dans umap
        }
        cout << "Numero de la commune recherchee:";
        cin >> numero;

        // COMPLETER : rechercher la commune et l’afficher

    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return 0;
}
