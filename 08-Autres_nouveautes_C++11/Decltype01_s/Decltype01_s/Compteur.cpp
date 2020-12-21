#include "stdafx.h"

#include <iostream>
#include "Compteur.h"
using namespace std;

Compteur::Compteur(){
	cpt=0;
}
Compteur::Compteur(int a){
	cpt=a;
}
void Compteur::increment(){
	cpt++;
}
bool Compteur::operator< (const Compteur& c) const {
	return cpt < c.cpt;
}
bool Compteur::operator> (const Compteur& c) const {
	return cpt > c.cpt;
}
int Compteur::getCpt() const{
	return cpt;
}
void Compteur::affiche()const{
	cout<<"valeur:"<<cpt<<std::endl;
}
std::ostream& operator<< (std::ostream& os, const Compteur& c){
	os<<c.getCpt();
	return os;
}
