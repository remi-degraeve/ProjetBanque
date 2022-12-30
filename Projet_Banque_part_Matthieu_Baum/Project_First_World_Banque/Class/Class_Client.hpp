#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "../Fonction_General.hpp"

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
    //Constructeur surchargée seulement utilisé pour des tests
    Client(int nume, string adrese, string prnom, string ndf, string MDP, vector<int> new_num_client) :num(nume), adresse(adrese), prenom(prnom), nom(ndf), mdp(MDP), num_client(new_num_client) {}
    //Construsteur utilisé lors de l'inscription d'un utilisateur
    Client(string adrese, string prnom, string ndf, string MDP);
    //récupére l'ID du client
    int Get_num();
    //récupére l'adresse du client
    string Get_adresse();
    //récupére le prénom du client
    string Get_prenom();
    //récupére le nom du client
    string Get_nom();
    //récupére le mot de passe du client
    string Get_mdp();
    //récupére le vector comportant tout les numéro de compte du client
    vector<int> Get_num_client();
    //modifie l'ID du Client
    void Set_num(int new_num);
    //modifie l'adresse du Client
    void Set_adresse(string new_adresse);
    //modifie le prénom du Client
    void Set_prenom(string new_prenom);
    //modifie le nom du Client
    void Set_nom(string new_nom);
    //modifie le mot de passe du Client
    void Set_mdp(string new_mdp);
    //modifie une valeurs du vecteur avec les num de comptes du client
    void Set_num_client_for_only_a_value(int new_num_client, int num_valeur);
    //permute le vector avec les num de comptes du client avec un autres utilisée dans la création d'un compte dans une banque
    void Set_num_client(vector<int> new_num_client);
};
