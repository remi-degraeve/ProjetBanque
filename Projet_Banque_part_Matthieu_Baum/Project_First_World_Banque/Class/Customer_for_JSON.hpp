#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "../Class/Class_Client.hpp"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

//permet de rajouter un numero de compte lors de la creation de compte dans une banque � un client et l'inscrire dans la base de donn�e
void add_account_numbers_for_a_client(int id_user,int num_compte);
//Transforme un client en ptree
ptree get_a_ptree_from_a_customer(Client& customer);
//fonction qui permet de v�rifi� si l'utilisateur existe dans la base de donn�e.
//cette fonction permet aussi de donner l'acc�s � un utilisateur � un compte si il a le bon mot de passe et le bon id utilisateur.
bool verify_connection(int id_user, std::string mdp);
//Transforme un ptree en objet de type Client
Client get_a_customer_from_a_ptree(ptree& pt);
//prend les valeurs d'un client et les transforment en ptree
ptree get_a_ptree_from_a_customer_values(int nume, string adrese, string prnom, string ndf, string MDP, vector<int> new_num_client);
//r�cup�re le nombre de client d'un ptree
int get_an_amount_of_client_from_a_ptree(ptree& pt);
//transforme un int en ptree
ptree get_a_ptree_from_an_amount_of_client(int Num_of_clients_in_db);
