#pragma once
#include <wx/wxprec.h>
#include <wx/event.h>
#include <wx/valnum.h>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "Customer_for_JSON.hpp"


#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "Customer_for_JSON.hpp"
#include "Customer_for_JSON.cpp"

using namespace std;


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Customer.hpp"
#include "My_new_Customer_dialog.hpp"




int get_an_amount_of_client_from_a_ptree(ptree& pt) {
    int num_of_client_in_db = pt.get<int>("Num_of_client", 0);
    return (num_of_client_in_db);
}

ptree get_a_ptree_from_an_amount_of_client(int Num_of_clients_in_db) {
    ptree pt;

    pt.put("Num_of_client", Num_of_clients_in_db);
    return pt;
}

ptree get_a_ptree_from_a_customer_values(int nume, string adrese, string prnom, string ndf, string MDP, vector<int> new_num_client) {
    ptree pt;
    ptree account_numbers;

    pt.put("Number", nume);
    pt.put("Name", ndf);
    pt.put("Prenom", prnom);
    pt.put("Adresse", adrese);
    pt.put("mdp", MDP);

    for (auto& account_number : new_num_client)
    {
        ptree dummy_tree;
        //   dummy_tree.put(account_number.first, account_number.second);
        dummy_tree.put_value(account_number);
        account_numbers.push_back({ "", dummy_tree });
    }
    pt.add_child("Account_numbers", account_numbers);
    return pt;
}


Client get_a_customer_from_a_ptree(ptree& pt)
{

    int number = pt.get<int>("Number", 0);

    std::string name = pt.get<std::string>("Name");
    std::string prenom = pt.get<std::string>("Prenom");
    std::string adresse = pt.get<std::string>("Adresse");
    std::string mdp = pt.get<std::string>("mdp");
    std::vector<int> account_numbers;

    for (ptree::value_type& account_number : pt.get_child("Account_numbers"))
    {
        account_numbers.push_back(account_number.second.get_value<int>());
    }

    Client customer(number, std::move(adresse), std::move(prenom), std::move(name), std::move(mdp), std::move(account_numbers));
    return customer;
}

Client::Client(string adrese, string prnom, string ndf, string MDP) {
    int num_total_client = 0;
    ptree pt_num;
    ptree pt_write;
    ptree pt_write2;
    ptree pt_account;

    this->adresse = adrese;
    this->prenom = prnom;
    this->nom = ndf;
    this->mdp = MDP;
    this->num_client;

    try {
        std::ifstream file_in("../Boost_JSON/DB_Client.json");
        read_json(file_in, pt_write2);
        file_in.close();



        for (ptree::value_type& cust : pt_write2.get_child("Amount_of_client")) {
            num_total_client = get_an_amount_of_client_from_a_ptree(cust.second);
            num_total_client++;
        }

        pt_num.push_back({ "",get_a_ptree_from_an_amount_of_client(num_total_client) });

        this->num = num_total_client;

        for (ptree::value_type& pt_accounts : pt_write2.get_child("Client")) {
            auto client = get_a_customer_from_a_ptree(pt_accounts.second);
            pt_account.push_back({ "", get_a_ptree_from_a_customer(client) });
        }
        pt_account.push_back({ "", get_a_ptree_from_a_customer_values(this->num,this->adresse,this->prenom,this->nom,this->mdp,this->num_client) });
        pt_write.add_child("Amount_of_client", pt_num);
        pt_write.add_child("Client", pt_account);

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

int Client::Get_num() { return (this->num); }
string Client::Get_adresse() { return (this->adresse); }
string Client::Get_prenom() { return (this->prenom); }
string Client::Get_nom() { return (this->nom); }
string Client::Get_mdp() { return (this->mdp); }
vector<int> Client::Get_num_client() { return (this->num_client); }
void Client::Set_num(int new_num) { this->num = new_num; }
void Client::Set_adresse(string new_adresse) { this->adresse = new_adresse; }
void Client::Set_prenom(string new_prenom) { this->prenom = new_prenom; }
void Client::Set_nom(string new_nom) { this->nom = new_nom; }
void Client::Set_mdp(string new_mdp) { this->mdp = new_mdp; }
void Client::Set_num_client(int new_num_client, int num_valeur) {
    if (num_valeur < this->num_client.size()) {
        this->num_client[num_valeur] = new_num_client;
    }
}

ptree get_a_ptree_from_a_customer(Client& customer)
{
    ptree pt;
    ptree account_numbers;

    pt.put("Number", customer.Get_num());
    pt.put("Name", customer.Get_nom());
    pt.put("Prenom", customer.Get_prenom());
    pt.put("Adresse", customer.Get_adresse());
    pt.put("mdp", customer.Get_mdp());

    for (auto& account_number : customer.Get_num_client())
    {
        ptree dummy_tree;
        //   dummy_tree.put(account_number.first, account_number.second);
        dummy_tree.put_value(account_number);
        account_numbers.push_back({ "", dummy_tree });
    }
    pt.add_child("Account_numbers", account_numbers);
    return pt;
}


void add_account_numbers_for_a_client(int id_user, int num_compte) {
    ptree pt_writ;
    ptree pt_writee;
    ptree pt_account;

    try {
        std::ifstream file_in("../Boost_JSON/DB_Client.json");
        read_json(file_in, pt_writ);
        file_in.close();

        for (ptree::value_type& pt_accounts : pt_writ.get_child("Client")) {
            Client client = get_a_customer_from_a_ptree(pt_accounts.second);
            if (client.Get_num() == id_user) {
                std::cout << "authentification réussi !" << std::endl;
                (client.Get_num_client()).push_back(num_compte);
            }
            else
            {

            }
        }
        std::cout << "authentification raté ! Votre numéro de client ou votre mot de passe doit avoir une erreur." << std::endl;
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }
}