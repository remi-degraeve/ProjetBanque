// Projet_Banque.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>
#include "../Class_Client/Class_Client.h"
#include "../Class_Banque/Class_Banque.h"
#include "../Class_Comptes/Class_Comptes.h"
#include "../Class_Transactions/Class_Transactions.h"


using namespace std;

// int Rand(int a, int b);


class class_Banque_Cen {

private:
    vector<class_Banque_Dec> tab_banques_dec;
    vector<Client> tab_clients_cen;
    vector<Comptes> tab_comptes_cen;
    vector<Transactions> tab_transactions_cen;

public:
    class_Banque_Cen();

    void set_tab_banques_dec(class_Banque_Dec Banque);
    void set_tab_clients_cen(Client Client);
    void set_tab_comptes_cen(Comptes Compte);
    void set_tab_transactions_cen(Transactions Transaction);

    Comptes get_tab_comptes_cen();
    Transactions get_tab_transactions_cen();


    Client creer_client(class_Banque_Cen Banque_Cen, string&& namedf, string&& name, vector<int>&& account_numbers, string&& adresss, string&& mdp);

    Client authentification(vector<int> num_client, string&& mdp);     // authentification avec num_client et mdp, retourne l'objet client
    class_Banque_Dec verification_Banque(Comptes& Compte, class_Banque_Dec Banque_Dec);   // retourne la bonne banque lorsque le client choisit un compte

};



// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre programme.
