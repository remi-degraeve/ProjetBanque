// Projet_Banque.cpp : définit le point d'entrée de l'application.
//

#include "Fonctions_General.h"

using namespace std;

//int Rand(int a,int b)
//{
//	int nRand;
//	nRand = a + (int)((int)rand() * (b - a + 1) / (RAND_MAX - 1));
//	return nRand;
//}

class_Banque_Cen::class_Banque_Cen() {

}


void class_Banque_Cen::set_tab_banques_dec(class_Banque_Dec Banque) {
	this->tab_banques_dec.push_back(Banque);
}



void class_Banque_Cen::set_tab_transactions_cen(Transactions Transaction) {
	this->tab_transactions_cen.push_back(Transaction);
}



//Client class_Banque_Cen:: creer_client(class_Banque_Cen Banque_Cen, string&& namedf, string&& name, vector<int>&& account_numbers, string&& adresss, string&& mdp) {
//	Client Client (namedf, adresss, name, mdp, account_numbers);
//	Banque_Cen.set_tab_clients_cen(Client);
//	return Client;
//}



//Client class_Banque_Cen::authentification(vector<int> num_client, string&& mdp) {
//	vector<Client>::iterator pFirst = tab_clients_cen.begin();
//	for (; pFirst != tab_clients_cen.end(); pFirst++) {
//		string num_client_str;
//		for (int i = 0; i < num_client.size(); i++){
//			char c = static_cast<int>(num_client.at(i));
//			num_client_str.push_back(c);
//		}
//		if ((*pFirst).Get_num_client() == num_client_str) {
//			if ((*pFirst).Get_mdp() == mdp) {
//				return *pFirst;
//			}
//			else {
//				//return 0;	// mettre en erreur
//			}
//		}
//		else {
//			//return 0;	// mettre en erreur
//		}
//	}
//}


class_Banque_Dec class_Banque_Cen::verification_Banque(Comptes& Compte, class_Banque_Dec Banque_Dec) {
	if (Compte.get_Nom_Banque() == Banque_Dec.get_nom_banque()) {
		return Banque_Dec;
	}
	else {
		vector<class_Banque_Dec>::iterator pFirst = tab_banques_dec.begin();
		for (; pFirst != tab_banques_dec.end(); pFirst++) {
			if ((*pFirst).get_nom_banque() == Compte.get_Nom_Banque()) {
				return *pFirst;
			}
		}
	}
}
