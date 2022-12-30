#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "../Class_Comptes/Class_Comptes.h"
#include "../Class_Transactions/Class_Transactions.h"

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

using namespace std;


class Client {
private:
    int num;
    string adresse;
    string prenom;
    string nom;
    string mdp;
    vector<int> num_client;
public:
    Client(int nume, string adrese, string prnom, string ndf, string MDP, vector<int> new_num_client) :num(nume), adresse(adrese), prenom(prnom), nom(ndf), mdp(MDP), num_client(new_num_client) {}
    Client(string adrese, string prnom, string ndf, string MDP);
    int Get_num();
    string Get_adresse();
    string Get_prenom();
    string Get_nom();
    string Get_mdp();
    vector<int> Get_num_client();
    void Set_num(int new_num);
    void Set_adresse(string new_adresse);
    void Set_prenom(string new_prenom);
    void Set_nom(string new_nom);
    void Set_mdp(string new_mdp);
    void Set_num_client(int new_num_client, int num_valeur);
};

//class Customer{
//private:
//    vector<int> num_client;
//    string nom;
//    string prenom;
//    string adresse;
//    string mdp;
//    vector<Comptes>tab_comptes_client;
//
//public:
//    Customer(string&& namedf, string&& name, vector<int>&& account_numbers, string&& adresss, string&& mdp);
//    vector <int>Create_New_num_client();
//    string Get_Num_Client();
//    string Get_Nom();
//    string Get_Prenom();
//    string Get_Adresse();
//    string Get_Mdp();
//
//    void set_Num_Client(string Num_Client);
//    void set_Nom(string Nom);
//    void set_Prenom(string Prenom);
//    void set_Adresse(string Adresse);
//    void set_Mdp(string Mdp);
//    void set_Compte(Comptes Compte);
//}; 

