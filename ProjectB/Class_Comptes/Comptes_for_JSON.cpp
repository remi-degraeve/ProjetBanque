#include "Comptes_for_JSON.hpp"

ptree get_a_ptree_from_a_compte(Comptes& compte)
{
    ptree pt;

    pt.put("Solde", compte.get_Solde());
    pt.put("Nom Banque", compte.get_Nom_Banque());
    pt.put("Date creation", compte.get_Date_Creation());
    pt.put("Taux interet", compte.get_Taux_Interet());


    ptree vectorNode;
    for (const auto& num : compte.get_Num_Client())
    {
        vectorNode.put("", num);
    }
    pt.add_child("num_Client", vectorNode);

    ptree vectorNodeT;
    for (const auto& transaction : compte.get_Transaction())
    {
        ptree transactionNode;
        transactionNode.put("Date", transaction.get_Date());
        transactionNode.put("Montant", transaction.get_num_proprietaire());
        transactionNode.put("Numero_Compte_Proprietaire", transaction.get_num_proprietaire());
        transactionNode.put("Numero_Compte_Correspondant", transaction.get_compte_corresp());
        vectorNodeT.push_back(std::make_pair("", transactionNode));
    }
    pt.add_child("Transactions", vectorNodeT);


    return pt;
}

Comptes get_a_compte_from_a_ptree(ptree& pt)
{

    float solde = pt.get<float>("Solde");
    std::string nom_Banque = pt.get<std::string>("Nom Banque");
    time_t date_Creation = pt.get<time_t>("Date creation");
    float taux_Interet = pt.get<float>("Taux interet");


    std::vector<int> num_Client;
    for (const auto& num_client_node : pt.get_child("Num_Client"))
    {
        num_Client.push_back(num_client_node.second.get_value<int>());
    }

    std::vector<Transaction> transactions;
    for (const auto& transaction_node : pt.get_child("Transactions"))
    {
        float montant = transaction_node.second.get<float>("Montant");
        std::string date = transaction_node.second.get<std::string>("Date");
        vector<int> Num_proprietaire = transaction_node.second.get<std::string>("Numero_Compte_Proprietaire");
        vector<int> Num_corresp = transaction_node.second.get<std::string>("Numero_Compte_Correspondant");

        transactions.emplace_back(montant, std::move(date), std::move(Num_proprietaire), std::move(Num_corresp));
    }



    Comptes compte(std::move(solde), std::move(num_Client), std::move(nom_Banque), std::move(date_Creation), std::move(taux_Interet), std::move(transactions));
    return compte;
}

