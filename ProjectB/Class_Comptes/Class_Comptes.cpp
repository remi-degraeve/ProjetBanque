// First_world_bank.cpp : définit le point d'entrée de l'application.
//

#include "Class_Comptes.h"

using namespace std;

// classe Comptes


Comptes::Comptes(float solde, vector<int> num_Client, string&& nom_banque, time_t date_Creation, float taux_interet) {
	this->solde = solde;
	/*for (int i = 0; i < num_Client.size(); i++)
	{
		this->num_Client.at(i) = num_Client.at(i);
	}*/
	this->num_Client = num_Client;
	this->nom_Banque = nom_banque;
	this->date_Creation = date_Creation;
	this->taux_Interet = taux_interet;
}


void Comptes::set_Transactions(Transactions& Transaction) {
	this->tab_Transactions.push_back(Transaction);
}

void Comptes::set_Solde(float Solde) {
	this->solde = Solde;
}

void Comptes::set_Num_Client(string Num_Client) {
	for (int i = 0; i < Num_Client.size(); i++)
	{
		this->num_Client.at(i) = Num_Client.at(i);
	}
}

void Comptes::set_Nom_Banque(string Nom_Banque) {
	this->nom_Banque = Nom_Banque;
}

void Comptes::set_Date_Creation(time_t Date_Creation) {
	this->date_Creation = Date_Creation;
}

void Comptes::set_Taux_Interet(int Taux_Interet) {
	this->taux_Interet = Taux_Interet;
}

void Comptes::set_Type(string Type) {
	this->type = Type;
}




float Comptes::get_Solde() {
	return(this->solde);
}

//string Comptes::get_Num_Client() {
//	string num_client_str;
//	for (int i = 0; i < this->num_Client.size(); i++)
//	{
//		char c = static_cast<int>(this->num_Client.at(i));
//		num_client_str.push_back(c);
//	}
//	return(num_client_str);
//}

vector<int> Comptes::get_Num_Client() {
	return num_Client;
}

string Comptes::get_Nom_Banque() {
	return this->nom_Banque;
}

time_t Comptes::get_Date_Creation() {
	return this->date_Creation;
}


float Comptes::get_Taux_Interet() {
	return this->taux_Interet;
}

string Comptes::get_Type() {
	return this->type;
}

vector<Transactions> Comptes::get_Transaction() {
	return tab_Transactions;
}



Comptes creer_compte(class_Banque_Dec Banque_Dec, Client Client, string nom_Banque, float solde, float taux_Interet) {
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<int> distr(1, 10);
	vector<int> num_Client;
	for (int i = 0; i < 7; i++) {
		num_Client.push_back(distr(eng));       // création du numero de compte
	}

	Client.Set_num_client(num_Client, 0);      // ajout dans le tableau de comptes du client;

	time_t now = time(0);       // date de création 

	Comptes Compte(solde, num_Client, nom_Banque, now, taux_Interet);   // création du compte

	Banque_Dec.set_tab_comptes_dec(Compte);     // ajout dans le tableau de comptes de la banqe decentralisee;

	return Compte;
}






// Evolution du compte epargne

void maj_Taux_Interet(Comptes Compte_Epargne) {
	int solde = Compte_Epargne.get_Solde();
	int taux_Interets = Compte_Epargne.get_Taux_Interet();
	int nouveau_solde = solde * taux_Interets;
	Compte_Epargne.set_Solde(nouveau_solde);
}


int simulation(float montant, time_t fin, int taux_interet) {
	time_t now = time(0);
	time_t temps = fin - now;
	int nmb_annee = temps / (365 * 3600 * 24);
	float reste = temps % (365 * 3600 * 24);
	for (int i = 0; i <= nmb_annee; i++) {
		montant *= taux_interet;
	}
	montant += montant * taux_interet * reste;
	return montant;
}



int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
