// Thread02.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cassert>

using namespace std;

const int max_sum_item = 1000000000;

void do_sum(long long* total)
{
    *total = 0;

    for (int i = 0; i < max_sum_item; i++) {
        *total += i;
    }
}

long do_sum_range(int debut, int fin)
{
    long total = 0;

    for (int i = debut; i < fin; i++) {
        total += i;
    }
    return total;
}

int main()
{
    long long result;

    std::cout << "Debut du calcul..." << std::endl;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    thread worker(do_sum, &result);

    worker.join();

    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // mes tests
    long plage = max_sum_item / 7;
    std::cout << "plage: " << plage << std::endl;

    long lResultat = 0;
    long debutPlage = 0;
    long finPlage = 0;
    long lResultatRange = 0;

    for (size_t i = 0; i < 7; i++)
    {
        finPlage = debutPlage + plage;
        lResultatRange = do_sum_range(debutPlage, finPlage);
        std::cout << "lResultatRange: " << lResultatRange << std::endl;
        lResultat += lResultatRange;
    }

    //lResultatRange = do_sum_range(1000, 2000);
    //std::cout << "Resultat: " << lResultatRange << std::endl;
    //lResultat += lResultatRange;

    //lResultatRange = do_sum_range(2000, 3000);
    //std::cout << "Resultat: " << lResultatRange << std::endl;
    //lResultat += lResultatRange;

    //lResultatRange = do_sum_range(3000, 4000);
    //std::cout << "Resultat: " << lResultatRange << std::endl;
    //lResultat += lResultatRange;

    std::cout << "Resultat global: " << lResultat << std::endl;

    std::cout << "Resultat: " << result << " obtenu en " << (end - start).count() * ((double)chrono::high_resolution_clock::period::num
        / chrono::high_resolution_clock::period::den) << "sec"
        << std::endl;

    return 0;
}
