#include "Customer_for_JSON.hpp"

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

