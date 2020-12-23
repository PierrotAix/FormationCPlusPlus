// Cpp01_s.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

// istream constructor
#include <iostream>     // std::ios, std::istream, std::cout
#include <fstream>      // std::filebuf

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
 {
    std::cout << "Bonjour!\n";

    fs::path p1 = "C:";
    p1 /= "Users"; // does not insert a separator
    std::cout << "\"C:\" / \"Users\" == " << p1 << '\n';
    p1 /= "batman"; // inserts fs::path::preferred_separator, '\' on Windows
    std::cout << "\"C:\" / \"Users\" / \"batman\" == " << p1 << '\n';



    std::filebuf fb;
    if (fb.open("C:\\Dev\\C++\\Github\\FormationCPlusPlus\\00-SandBox\\Cpp01_s\\valeurs.txt", std::ios::in))
    {
        std::istream is(&fb);
        while (is)
            std::cout << char(is.get());
        fb.close();
    }
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
