// Projet_Banque.cpp : définit le point d'entrée de l'application.
//

#include "Class_Transactions.h"


using namespace std;

Transactions::Transactions(vector<int> num_proprietaire, vector<int> num_corresp, int Montant, string Date) {
	montant = Montant;
	date = Date;
	num_proprietaire = num_proprietaire;
	num_corresp = num_corresp;
}




//Transactions::Transactions(Comptes Compte_proprietaire, Comptes Compte_corresp, int Montant, string Date) {
//	Compte_proprietaire = Compte_proprietaire;
//	Compte_corresp = Compte_corresp;
//	montant = Montant;
//	date = Date;
//}


void Transactions::Faire_Transactions(Comptes Compte_A, Comptes Compte_B, int Montant, class_Banque_Dec Banque) {
	// Date
	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form : the local date is Sat Jan  8 20:07:41 2011
	char* dt = ctime(&now);
	// convert now to tm struct for UTC : The UTC date and time is Sun Jan  9 03:07:41 2011
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);


	// Crédit sur le compte du client B
	int solde_B = Compte_B.get_Solde();
	solde_B += Montant;
	Compte_B.set_Solde(solde_B);

	// Debit sur le compte du client A
	int solde_A = Compte_A.get_Solde();
	solde_A -= Montant;
	Compte_A.set_Solde(solde_A);

	// Mise à jour tableau transactions du client A
	int montant_A = -(Montant);
	Transactions Transaction_A(Compte_A.get_Num_Client(), Compte_B.get_Num_Client(), montant_A, dt);
	Compte_A.set_Transactions(Transaction_A);

	// Mise à jour tableau transactions du client B
	Transactions Transaction_B(Compte_B.get_Num_Client(), Compte_A.get_Num_Client(), Montant, dt);
	Compte_B.set_Transactions(Transaction_B);

	// Mise à jour tableau de transaction de la banque decentralisee de compteA
	Banque.set_tab_transactions_dec(Transaction_A);

}



string Transactions::get_Date() {
	return this->date;
}

//Comptes Transactions::get_Compte_proprietaire() {
//	return this->Compte_proprietaire;
//}
//
//Comptes Transactions::get_Compte_corresp() {
//	return this->Compte_corresp;
//}

vector<int> Transactions::get_num_proprietaire() {
	return(num_proprietaire);

}

vector<int> Transactions::get_num_corresp() {
	return(num_corresp);
}


int Transactions::get_Montant() {
	return this->montant;
}





