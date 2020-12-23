// RootFinder.cpp : Définit les fonctions exportées de la DLL.
//

#include "framework.h"
#include "RootFinder.h"
#include <math.h>
#include <stdexcept>

// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

// To output into the Sortie
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <filesystem>

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}
// example :    DBOUT("some text " << some_variable << "   some more text" << some_other_varaible << "\n");


//namespace fs = std::filesystem;
using namespace std::string_literals;

// Il s'agit d'un exemple de variable exportée
ROOTFINDER_API int nRootFinder=0;

// Il s'agit d'un exemple de fonction exportée.
ROOTFINDER_API int fnRootFinder(void)
{
    return 0;
}

// Il s'agit du constructeur d'une classe qui a été exportée.
CRootFinder::CRootFinder()
{
    return;
}

double CRootFinder::SquareRoot(double v)
{
    // Validate parameter:
    if (v < 0.0)
    {
        throw std::out_of_range("On ne peut pas faire de racine carre de nombres negatifs.");
    }
    double result = v;
    double diff = v;
    while (diff > result/1000)
    {
        double oldResult = result;
        //old code:
        //result = result - (result * result - v) / (2 * result);
        // new code:
        result = (result + v / result) / 2.0;
        diff = fabs(oldResult - result);
    }
    return result;
}

double CRootFinder::Addition(double p1, double p2)
{
    double lResult = p1 + p2;
    return lResult;
}

string CRootFinder::GetLine(string pHeading, string pKeyWord, string pBasePath, string pRelativePath, string pChecksum)
{
    string lResult = "Resultat";
    return lResult;
}

/// <summary>
/// http://www.cplusplus.com/reference/istream/istream/read/
/// </summary>
/// <param name="pFileName"></param>
/// <returns></returns>
int CRootFinder::GetNumberOfCharactersOfFile(string pFileName)
{
    int result = 0;

    ifstream is(pFileName, ifstream::binary);
    //ifstream is ("valeurs.txt");
    if (is) {
        // get length of file:
        is.seekg(0, is.end);
        int length = is.tellg();
        result = length;
        is.seekg(0, is.beg);

        char* buffer = new char[length];

        DBOUT("DEBUG Reading " << length << " characters... " << "\n");
        // read data as a block:
        is.read(buffer, length);

        if (is)
        {
            //cout << "all characters read successfully.";
            DBOUT("DEBUG all characters read successfully." << "\n");
        }
        else
        {
            cout << "error: only " << is.gcount() << " could be read";
            DBOUT("DEBUG error: only " << is.gcount() << " could be read" << "\n");
        }
            
        is.close();

        // ...buffer contains the entire file...

        delete[] buffer;
    }
    else
    {
        DBOUT("Impossible to read the file"  << "\n");
    }
    return result;
}

int CRootFinder::GetNumberOfCharactersOfFile(string pBasePath, string pRelativePath)
{
    int result = 0;

    //std::fi

    return result;
}


