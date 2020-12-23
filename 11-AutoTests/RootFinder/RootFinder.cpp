// RootFinder.cpp : Définit les fonctions exportées de la DLL.
//

#include "framework.h"
#include "RootFinder.h"
#include <math.h>
#include <stdexcept>


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
        throw std::out_of_range("On ne peut pas faire de racine crré de nombres négatifs.");
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
