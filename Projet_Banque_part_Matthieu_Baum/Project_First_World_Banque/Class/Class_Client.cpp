// Project_First_World_Banque.cpp : définit le point d'entrée de l'application.
//
#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "Class_Client.hpp"
#include "Customer_for_JSON.hpp"

//construsteur utilisé lors de l'inscription d'un utilisateur
Client::Client(string adrese, string prnom, string ndf, string MDP) {
    int num_total_client = 0;
    ptree pt_num;
    ptree pt_write;
    ptree pt_write2;
    ptree pt_account;

    //assigne les valeurs données par l'utilisateur à son objet
    this->adresse = adrese;
    this->prenom = prnom;
    this->nom = ndf;
    this->mdp = MDP;
    this->num_client;

    try {
        //ouvre la base de donnée
        std::ifstream file_in("../Boost_JSON/DB_Client.json");
        read_json(file_in, pt_write2);
        file_in.close();


        //récupére le nombre de client déjà inscrit dans la base de données 
        for (ptree::value_type& cust : pt_write2.get_child("Amount_of_client")) {
            num_total_client = get_an_amount_of_client_from_a_ptree(cust.second);
            //rajoute 1 au nombre de client total, cette variable correspond au futur ID de notre utilisateur
            num_total_client++;
        }
        //inscrit dans un ptree les modification apportée (un client est inscrit en plus dans la Base de Données)
        pt_num.push_back({ "",get_a_ptree_from_an_amount_of_client(num_total_client) });

        //l'ID de l'utilisateur devient n+1 client inscrit dans la base données.
        this->num = num_total_client;

        //inscrit le nouvelle objet créer dans la base existante en extractant les clients déjà présent dans la Base de données et en rajoutant notre client
        for (ptree::value_type& pt_accounts : pt_write2.get_child("Client")) {
            auto client = get_a_customer_from_a_ptree(pt_accounts.second);
            //reprend tout les clients de la base et les introduit dans un arbre
            pt_account.push_back({ "", get_a_ptree_from_a_customer(client) });
        }
        //rajoute notre client à l'arbre
        pt_account.push_back({ "", get_a_ptree_from_a_customer_values(this->num,this->adresse,this->prenom,this->nom,this->mdp,this->num_client) });
        pt_write.add_child("Amount_of_client", pt_num);
        pt_write.add_child("Client", pt_account);
        //écrit le tout dans notre base de données.
        std::ofstream file_out("../Boost_JSON/DB_Client.json");
        write_json(file_out, pt_write);
        file_out.close();

        
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }

};
//récupére l'ID du client
int Client::Get_num() { return (this->num); }
//récupére l'adresse du client
string Client::Get_adresse() { return (this->adresse); }
//récupére le prénom du client
string Client::Get_prenom() { return (this->prenom); }
//récupére le nom du client
string Client::Get_nom() { return (this->nom); }
//récupére le mot de passe du client
string Client::Get_mdp() { return (this->mdp); }
//récupére le vector comportant tout les numéro de compte du client
vector<int> Client::Get_num_client() { return (this->num_client); }
//modifie l'ID du Client
void Client::Set_num(int new_num) { this->num = new_num; }
//modifie l'adresse du Client
void Client::Set_adresse(string new_adresse) { this->adresse = new_adresse; }
//modifie le prenom du Client
void Client::Set_prenom(string new_prenom) { this->prenom = new_prenom; }
//modifie le nom du Client
void Client::Set_nom(string new_nom) { this->nom = new_nom; }
//modifie le mot de passe du Client
void Client::Set_mdp(string new_mdp) { this->mdp = new_mdp; }
//modifie une valeurs du vecteur avec les num de comptes du client
void Client::Set_num_client_for_only_a_value(int new_num_client, int num_valeur) {
    if (num_valeur < this->num_client.size()) {
        this->num_client[num_valeur] = new_num_client;
    }
}
//permute le vector avec les num de comptes du client avec un autres utilisée dans la création d'un compte dans une banque
void Client::Set_num_client(vector<int> new_num_clients) {
    this->num_client = new_num_clients;
}