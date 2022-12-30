// First_world_bank.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <random>
#include <iomanip>

#include "../Class_Comptes/Class_Comptes.h"
#include "../Class_Transactions/Class_Transactions.h"


using namespace std;

//class class_Banque {
//
//private:
//
//    vector<int> tab_num_client;
//    vector<vector<int>> tab_comptes_client;
//    vector<int> tab_banque;
//    string nom;
//    int num_banque;
//    int nb_banque;
//
//public:
//    //class_Banque();
//    class_Banque(const string& nom);
//
//
//   // void set_tab_num_client(const int& new_tab_num_client);
//    void set_tab_banque(const int& new_tab_banque);
//    void set_num_banque(const int& new_num_banque);
//    void set_nom(const string& new_nom);
//
//    // vector<int> get_tab_num_client();
//    vector<int> get_tab_banque();
//    int get_num_banque();
//    string get_nom();
//    int get_size_tab_comptes();
//
//    char verification_Banque(int num_Client);   // retourne la bonne banque 
//
//};


class class_Banque_Dec {

private:
    string nom_banque;
    vector<Comptes> tab_comptes_dec;
    vector<Transactions> tab_transactions_dec;

public:
    class_Banque_Dec(const string& nom);
    class_Banque_Dec(const string& nom, vector<Comptes>tab_comptes_dec, vector<Transactions> tab_transactions_dec) :
        nom_banque(std::move(nom)), tab_comptes_dec(std::move(tab_comptes_dec)), tab_transactions_dec(std::move(tab_transactions_dec))
    {}
    void set_nom_banque(const string& new_nom);
    void set_tab_comptes_dec(Comptes& Compte);
    void set_tab_transactions_dec(Transactions& Transaction);

    string get_nom_banque();
    // Comptes get_tab_comptes_dec();
    // Transactions get_tab_transactions_dec();



};





// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre programme.
