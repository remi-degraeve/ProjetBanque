#include "Transactions_for_JSON.hpp"


ptree get_a_ptree_from_a_transaction(Transactions& transaction);
{
    ptree pt;
    ptree account_numbers;

    pt.put("Date", transaction.get_Date());
    pt.put("Numero_Compte_Proprietaire", transaction.get_num_proprietaire());
    pt.put("Numero_Compte_Correspondant", transaction.get_compte_corresp());
    pt.put("Montant", transaction.get_Montant());

}

Transactions get_a_transaction_from_a_ptree(ptree& pt)
{
    std::string date = pt.get<std::string>("Date");
    float montant = pt.get<float>("Montant");

    vector<int> Num_proprietaire = pt.get<std::string>("Numero_Compte_Proprietaire");
    vector<int> Num_corresp = pt.get<std::string>("Numero_Compte_Correspondant");


    Transactions transaction(std::move(Num_proprietaire), std::move(Num_corresp), std::move(nom_Banque), montant, std::move(date));
    return transaction;
}

