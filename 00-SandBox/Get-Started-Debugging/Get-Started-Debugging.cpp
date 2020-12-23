// Get-Started-Debugging.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <sstream>

#ifdef DEBUG   
System::Diagnostics::Debug::WriteLine("your message");
#endif 

#include <Windows.h>

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}
// example :    DBOUT("some text " << some_variable << "   some more text" << some_other_varaible << "\n");

void SendMessage(const std::wstring& name, int msg)
{
    std::wcout << L"Hello, " << name << L"! Count to " << msg << std::endl;
    DBOUT("The value of name is " << name);
}

int main()
{
    std::cout << "Hello World!\n";
    DBOUT("some text " << "\n");
    //System::Diagnostics::Debug::WriteLine("your message");

    std::vector<wchar_t> letters = { L'f', L'r', L'e', L'd', L' ', L's', L'm', L'i', L't', L'h' };
    std::wstring name = L"";
    std::vector<int> a(10);
    std::wstring key = L"";

    for (int i = 0; i < letters.size(); i++)
    {
        name += letters[i];
        a[i] = i + 1;
        SendMessage(name, a[i]);
    }
    std::wcin >> key;
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
