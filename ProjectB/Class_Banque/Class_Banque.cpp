// First_world_bank.cpp : définit le point d'entrée de l'application.
//

#include "Class_Banque.h"

using namespace std;


class_Banque_Dec::class_Banque_Dec(const string& nom) {
    this->nom_banque = nom;
}



void class_Banque_Dec::set_nom_banque(const string& new_nom) {
    this->nom_banque = new_nom;
}

void class_Banque_Dec::set_tab_comptes_dec(Comptes& Compte) {
    this->tab_comptes_dec.push_back(Compte);
}

void class_Banque_Dec::set_tab_transactions_dec(Transactions& Transaction) {
    this->tab_transactions_dec.push_back(Transaction);
}

string class_Banque_Dec::get_nom_banque() {
    return this->nom_banque;
}





int main()
{
    class_Banque_Dec Banque_Dec("SG");

}
