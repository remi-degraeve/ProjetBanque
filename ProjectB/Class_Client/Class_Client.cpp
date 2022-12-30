// First_world_bank.cpp : définit le point d'entrée de l'application.
//

#include "Class_Client.h"
#include "../Class_Comptes/Class_Comptes.h"
#include "../Fonctions_general/Fonctions_general.h"
#include "../Fonctions_general/Fonctions_general.cpp"


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


//Customer::Customer(string&& namedf, string&& name, vector<int>&& account_numbers, string&& adresss, string&& mdp) {
//    this->nom= namedf;
//    this->prenom=name; 
//    this->adresse=adresss;
//    this->mdp=mdp;
//    for (int i = 0; i < account_numbers.size(); i++){
//        this->num_client.at(i) = account_numbers.at(i);
//    }
//
//}
//
//
//void Customer::set_Num_Client(string Num_Client) {
//    if (Num_Client.size() != this->num_client.size()) {
//        cout << "le numéro entré est trop court par rapport au numéro existant" << endl;
//        return;
//    }
//    else
//    {
//        for (int i = 0; i < Num_Client.size(); i++)
//        {
//            this->num_client.at(i) = Num_Client.at(i);
//        }
//    }
//}
//void Customer::set_Nom(string Nom) {
//    this->nom = Nom;
//}
//void Customer::set_Prenom(string Prenom) {
//    this->prenom = Prenom;
//}
//void Customer::set_Adresse(string Adresse) {
//    this->adresse = Adresse;
//}
//void Customer::set_Mdp(string Mdp) {
//    this->mdp = Mdp;
//}
//
//void Customer::set_Compte(Comptes Compte) {
//    tab_comptes_client.push_back(Compte);
//}
//
//
//string Customer::Get_Num_Client() {
//    string num_client_str;
//    for (int i = 0; i < this->num_client.size(); i++)
//    {
//        char c = static_cast<int>(this->num_client.at(i));
//        num_client_str.push_back(c);
//    }
//    return(num_client_str);
//}
//string Customer::Get_Nom() {
//    return(this->nom);
//}
//string Customer::Get_Prenom() {
//    return(this->prenom);
//}
//string Customer::Get_Adresse() {
//    return(this->adresse);
//}
//string Customer::Get_Mdp() {
//    return(this->mdp);
//}





