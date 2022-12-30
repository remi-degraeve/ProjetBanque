// Projet_Banque.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once

#include <iostream>
#include <cTime>
#include <vector>
#include "../Class_Comptes/Class_Comptes.h"
#include "../Class_Banque/Class_Banque.h"

using namespace std;

class Transactions {

private:
    string date;
    vector<int> num_proprietaire;
    vector<int> num_corresp;

    /*Comptes Compte_proprietaire;
    Comptes Compte_corresp;*/
    int montant;

public:

    string get_Date();
    /*Comptes get_Compte_proprietaire();
    Comptes get_Compte_corresp();*/
    vector<int> get_num_proprietaire();
    vector<int> get_num_corresp();
    int get_Montant();

    Transactions(vector<int> num_proprietaire, vector<int> num_corresp, int Montant, string Date);
    //Transactions(Comptes Compte_proprietaire, Comptes Compte_corresp, int Montant, string Date);
    void Faire_Transactions(Comptes Compte_A, Comptes Compte_B, int Montant, class_Banque_Dec Banque);

};


// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre programme.
