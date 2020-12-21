// UnorderedMap01_s.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
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
    auto pfichier = std::unique_ptr<ifstream, decltype(deleter)>(new ifstream("code_postaux.txt"),deleter);

    if (*pfichier)
    {
        while (getline(*pfichier, ligne))
        {
            std::istringstream iss(ligne);
            std::vector<std::string> commune((std::istream_iterator<SplitChaine<'\t'>>(iss)),
                std::istream_iterator<SplitChaine<'\t'>>());
            cout << commune[1] << " " << commune[0] << endl;
            
            umap.insert(make_pair(commune[1], commune[0]));
        }
        cout << "Numero de la commune recherchee:";
        cin >> numero;
        auto code = umap.find(numero);
        if (code == umap.end())
            cout << "commune non trouvee" << endl;
        else
            cout << "commune trouvee: " << code->second << " (" << code->first << ")" << endl;
    }
    else
    {
        cerr << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return 0;
}