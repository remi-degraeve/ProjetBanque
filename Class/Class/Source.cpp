#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class Client {

private:

	int num_client;
	string nom;
	string prenom;
	string adresse;
	int tab_transaction[100];
	int tab_comptes[100];

public:

	
};


class Banque {

private:

	int tab_client[100];
	string nom;
	int num_banque;

public:


};



class Transaction {

private:

	int time;
	int montant;
	int num_client;

public:


};

class Compte {

private:

	int money;
	int  banque_nom;
	bool compte_epargne;

public:


};

int main(){

}