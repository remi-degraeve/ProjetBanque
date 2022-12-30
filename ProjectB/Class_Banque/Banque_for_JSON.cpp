#include "Banque_for_JSON.hpp"
#include "Customer_for_JSON.hpp"
#include "Transactions_for_JSON.hpp"
#include "Customer_for_JSON.hpp"

ptree get_a_ptree_from_a_banque_dec(class_Banque_Dec& Banque_dec)
{
    ptree pt;

    pt.put("Nom Banque", Banque_dec.get_nom_banque());


    for (const auto& account_node : pt.get_child("Comptes"))
    {
        Comptes Comptes;
        Comptes.get_a_compte_from_a_ptree(account_node.second);
        Comptes.push_back(Comptes);
    }


    ptree vectorNodeT;
    for (const auto& transaction : tab_transactions_dec()
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

class_Banque_Dec get_a_banque_dec_from_a_ptre(ptree& pt)
{
    std::string nom_Banque = pt.get<std::string>("Nom Banque");


    std::vector<Transaction> transactions;
    for (const auto& transaction_node : pt.get_child("Transactions"))
    {
        float montant = transaction_node.second.get<float>("Montant");
        std::string date = transaction_node.second.get<std::string>("Date");
        vector<int> Num_proprietaire = transaction_node.second.get<std::string>("Numero_Compte_Proprietaire");
        vector<int> Num_corresp = transaction_node.second.get<std::string>("Numero_Compte_Correspondant");

        transactions.emplace_back(montant, std::move(date), /*std::move(Comptes), */std::move(transactions));
    }



    class_Banque_Dec Banque_dec(std::move(nom_Banque), std::move(num_Client), std::move(transactions));
    return compte;
}

