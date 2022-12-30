// First_world_bank.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma once

#include <iostream>
#include <cTime>
#include <vector>
#include "../Class_Client/Class_Client.h"
#include "../Class_Transactions/Class_Transactions.h"
#include "../Class_Banque/Class_Banque.h"

using namespace std;



class Comptes {

private:
	float solde;
	vector<int> num_Client;
	string nom_Banque;
	vector<Transactions> tab_Transactions;
	time_t date_Creation;

	float taux_Interet;
	string type;


public:
	Comptes();
	Comptes(float solde, vector<int> num_Client, string&& nom_banque, time_t date_Creation, float taux_interet);
	Comptes(float solde, vector<int> num_Client, string&& nom_banque, time_t date_Creation, float taux_interet, vector<Transactions> tab_Transactions) :
		solde(solde), num_Client(std::move(num_Client)), nom_Banque(std::move(nom_banque)), date_Creation(date_Creation), taux_Interet(taux_interet), tab_Transactions(std::move(tab_Transactions))
	{}

	void set_Solde(float Solde);
	void set_Num_Client(string Num_Client);
	void set_Nom_Banque(string Nom_Banque);
	void set_Transactions(Transactions& Transaction);
	void set_Date_Creation(time_t Date_Creation);
	void set_Taux_Interet(int Taux_Interet);
	void set_Type(string Type);


	float get_Solde();
	vector<int> get_Num_Client();
	string get_Nom_Banque();
	time_t get_Date_Creation();
	float get_Taux_Interet();
	string get_Type();
	Transactions get_Transaction();
};



//class Compte_Epargne : public Comptes {
//private:
//	int taux_Interet;
//	string type;
//
//public:
//	Compte_Epargne(const int& solde, const int& num_compte, string&& nom_banque, time_t date_Creation, int taux_interet);
//
//	void set_Taux_Interet(int Taux_Interet);
//	void set_Type(string Type);
//
//	int get_Taux_Interet();
//	string get_Type();
//};

Comptes creer_compte(Client Client, string nom_Banque, float solde, float taux_Interet);

void maj_Taux_Interet(Comptes Compte_Epargne);
int simulation(float montant, int fin, int taux_interet);


// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre programme.
