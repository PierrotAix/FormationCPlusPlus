// Thread05.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <thread>
#include "restaurant.h"

/*
Le serveur :
    prévient le chef de l'arrivée d'une nouvelle commande
    attends que le chef déclenche la sonnette
    sert le plat

Le chef :
    attends l'arrivée d'une nouvelle commande
    cuisine le plat commandé
    déclenche la sonnette pour prévenir le serveur

*/

int main() {
    Restaurant restaurant;
    std::thread chef(&Restaurant::chef, std::ref(restaurant));
    std::thread serveur(&Restaurant::serveur, std::ref(restaurant));
    chef.join();
    serveur.join();

    return 0;
}