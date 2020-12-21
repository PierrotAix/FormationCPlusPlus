#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

class Restaurant {
    enum class Etat { en_attente, nouvelle_commande, pret }; //
    Etat etatCommande = Etat::en_attente;
    std::mutex commande;
    std::condition_variable sonnette_commande;

public:

    void chef() {

        std::unique_lock<std::mutex> ul(commande);
        sonnette_commande.wait(ul, [=]() { return etatCommande == Etat::nouvelle_commande; }); // COMPLETER: attente via sonnette_commande d'une nouvelle commande 
        
        cout << "le chef prepare le plat..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "le plat est pret a etre servi..." << endl;
        
        etatCommande = Etat::pret;
        sonnette_commande.notify_one(); // COMPLETER: prévenir via sonnette_commande que la commande est prete 

    }

    void serveur() {
        cout << "le serveur prends une nouvelle commande" << endl; 
        this_thread::sleep_for(chrono::seconds(2)); 
        {
            // COMPLETER: début de section critique
            std::lock_guard<std::mutex> lg(commande);
            etatCommande = Etat::nouvelle_commande;
            sonnette_commande.notify_one();
            // COMPLETER: fin de section critique

        } //commande.unlock()

        // COMPLETER: début de section critique
        std::unique_lock<std::mutex> ul(commande);
        sonnette_commande.wait(ul, [=]() { return etatCommande == Etat::pret; }); // COMPLETER: attente via sonnette_commande que le plat est prêt
        etatCommande = Etat::en_attente;
        ul.unlock();
        // COMPLETER: fin de section critique
        
        cout << "le serveur prends le plat" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "le plat est servi..." << endl;
    }

};