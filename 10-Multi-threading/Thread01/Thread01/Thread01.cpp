// Thread01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

    //class thread_obj {
    //public:
    //    void operator()(int x) {
    //        for (int i = 0; i < x; i++)
    //            cout << "Foncteur\n"
    //    }
    //};

    struct Rebours
    {
        int m_secs;

        Rebours(int secs) : m_secs(secs) { }

        void operator()() {
            cout << "Dans rebour\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    };

    void foo(int Z) {
        for (int i = 0; i < Z; i++) {
            cout << "Pointeur sur fonction\n";
        }
    }

    int main() {

        // Expression Lambda
        auto f = [](int x) {
            for (int i = 0; i < x; i++)
                cout << "Expression lambda\n";
        };


        thread th1(Rebours(5));
        thread th3(f, 3);

        // attente fin des threads
        th1.join();
        th3.join();

        // A COMPLETER	

        return 0;
    }


