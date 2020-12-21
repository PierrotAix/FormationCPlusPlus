// Pattern06.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "ClockTimer.h"
#include "DigitalClock.h"

int main()
{
    ClockTimer timer;

    DigitalClock digitalClock(timer);

    timer.SetTime(14, 41, 36);
}
