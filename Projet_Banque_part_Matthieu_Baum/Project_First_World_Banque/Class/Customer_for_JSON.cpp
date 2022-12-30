#include "Customer_for_JSON.hpp"
#include "Class_Client.hpp"

//Transforme un client en ptree
ptree get_a_ptree_from_a_customer(Client& customer)
{
    ptree pt;
    ptree account_numbers;

    //on ajoute dans un ptree toutes les variables de notre client avec un string pour pouvoir ensuite le d�marquer
    pt.put("Number", customer.Get_num());
    pt.put("Name", customer.Get_nom());
    pt.put("Prenom", customer.Get_prenom());
    pt.put("Adresse", customer.Get_adresse());
    pt.put("mdp", customer.Get_mdp());
    //m�me chose mais dans ce cas num_client et un vector comportant plusieur variable.
    for (auto& account_number : customer.Get_num_client())
    {
        //on cr�er alors un ptree dans notre ptree qui comporte les variables du vector
        ptree dummy_tree;
        dummy_tree.put_value(account_number);
        account_numbers.push_back({ "", dummy_tree });
    }
    //on cr�er une sous cat�gorie pour le vector
    pt.add_child("Account_numbers", account_numbers);
    //on finie par retourn� le tout sous forme d'un ptree
    return pt;
}

//fonction qui permet de v�rifi� si l'utilisateur existe dans la base de donn�e.
//cette fonction permet aussi de donner l'acc�s � un utilisateur � un compte si il a le bon mot de passe et le bon id utilisateur.
bool verify_connection(int id_user, std::string mdp) {

    ptree pt_writ;
    ptree pt_account;
    try {
        //on cr�er un ptree avec les �l�ments de la base de donn�e.
        std::ifstream file_in("../Boost_JSON/DB_Client.json");
        read_json(file_in, pt_writ);
        file_in.close();

        //on traduit tout les �l�ments de la base de donn�e en client
        for (ptree::value_type& pt_accounts : pt_writ.get_child("Client")) {
            //on traduit tout les �l�ments de la base de donn�e en client
            Client client = get_a_customer_from_a_ptree(pt_accounts.second);
            //si le mdp existe et si il est �gale � celui renseigner ET l'id du client et le m�me que celui renseigner alors :
            if (client.Get_mdp() == mdp && client.Get_num() == id_user) {
                //acc�s donn� au client.
                std::cout << "authentification r�ussi !" << std::endl;
                return true;
            }
        }
        //sinon un message d'erreur s'affiche.
        std::cout << "authentification rat� ! Votre num�ro de client ou votre mot de passe doit avoir une erreur." << std::endl;
        return false;
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }
}

//permet de rajouter un numero de compte lors de la creation de compte dans une banque � un client et l'inscrire dans la base de donn�e
void add_account_numbers_for_a_client(int id_user, const int num_compte) {
    ptree pt_writ;
    ptree pt_writee;
    ptree pt_acount;
    ptree pt_nume;
    int num_total_client=0;

    try {
        //on cr�er un ptree avec les �l�ments de la base de donn�e.
        std::ifstream file_in("../Boost_JSON/DB_Client.json");
        read_json(file_in, pt_writ);
        file_in.close();
        //on recopie le nombre de clients dans la base de donn�e
        for (ptree::value_type& cust : pt_writ.get_child("Amount_of_client")) {
            num_total_client = get_an_amount_of_client_from_a_ptree(cust.second);
        }
        //on l'incorpore dans un arbre
        pt_nume.push_back({ "",get_a_ptree_from_an_amount_of_client(num_total_client) });

        //on transforme chaque enfant en ptree que l'on transforme en Client
        for (ptree::value_type& pt_accounts : pt_writ.get_child("Client")) {
            Client client = get_a_customer_from_a_ptree(pt_accounts.second);
            //si on retrouve le client avec son id alors :
            if (client.Get_num() == id_user) {
                //std::cout << "MATCH !" << std::endl;
                //on recopie son vector.
                vector<int> tmp = client.Get_num_client();
                //on rajoute le numero � rajouter.
                tmp.push_back(num_compte);
                //on remplace l'ancien vector avec le nouveau.
                client.Set_num_client(tmp);
                //on incorpore le client dans un arbre
                pt_acount.push_back({ "", get_a_ptree_from_a_customer(client) });
            }
            //sinon
            else
            {
                //std::cout << "NO MATCH !" << std::endl;
                //on rajoute juste le client � l'arbre.
                pt_acount.push_back({ "", get_a_ptree_from_a_customer(client) });
            }
        }
        pt_writee.add_child("Amount_of_client", pt_nume);
        pt_writee.add_child("Client", pt_acount);
        //on r��crit dans la base de donn�e le tout.
        std::ofstream file_out("../Boost_JSON/DB_Client.json");
        write_json(file_out, pt_writee);
        file_out.close();
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }
}

//Transforme un ptree en objet de type Client
Client get_a_customer_from_a_ptree(ptree& pt)
{
    //assigne � la valeur number � la variable de la node "Number" du ptree
    int number = pt.get<int>("Number", 0);
    //assigne � la valeur name � la variable de la node "Name" du ptree
    std::string name = pt.get<std::string>("Name");
    //assigne � la valeur prenom � la variable de la node "Prenom" du ptree
    std::string prenom = pt.get<std::string>("Prenom");
    //assigne � la valeur adresse � la variable de la node "Adresse" du ptree
    std::string adresse = pt.get<std::string>("Adresse");
    //assigne � la valeur mdp � la variable de la node "mdp" du ptree
    std::string mdp = pt.get<std::string>("mdp");
    std::vector<int> account_numbers;
    //prend les valeurs de l'enfant "Account_numbers" et les incorpore dans un vector
    for (ptree::value_type& account_number : pt.get_child("Account_numbers"))
    {
        account_numbers.push_back(account_number.second.get_value<int>());
    }
    //cr�er le client avec le constructeur surcharg�e
    Client customer(number, std::move(adresse), std::move(prenom),std::move(name), std::move(mdp), std::move(account_numbers));
    return customer;
}

//r�cup�re le nombre de client d'un ptree
int get_an_amount_of_client_from_a_ptree(ptree& pt) {
    //assigne � la valeur num_of_client_in_db � la variable de la node "Num_of_client" du ptree
    int num_of_client_in_db = pt.get<int>("Num_of_client", 0);
    return (num_of_client_in_db);
}

//transforme un int en ptree
ptree get_a_ptree_from_an_amount_of_client(int Num_of_clients_in_db) {
    ptree pt;
    //incorpore dans un ptree la variable Num_of_clients_in_db dans un ptree
    pt.put("Num_of_client", Num_of_clients_in_db);
    return pt;
}

//prend les valeurs d'un client et les transforment en ptree
ptree get_a_ptree_from_a_customer_values(int nume, string adrese, string prnom, string ndf, string MDP, vector<int> new_num_client) {
    ptree pt;
    ptree account_numbers;

    //on ajoute dans un ptree toutes les variables de notre client avec un string pour pouvoir ensuite le d�marquer
    pt.put("Number", nume);
    pt.put("Name", ndf);
    pt.put("Prenom", prnom);
    pt.put("Adresse", adrese);
    pt.put("mdp", MDP);

    //m�me chose mais dans ce cas num_client et un vector comportant plusieur variable.
    for (auto& account_number : new_num_client)
    {
        //on cr�er alors un ptree dans notre ptree qui comporte les variables du vector
        ptree dummy_tree;
        dummy_tree.put_value(account_number);
        account_numbers.push_back({ "", dummy_tree });
    }
    //on cr�er une sous cat�gorie pour le vector
    pt.add_child("Account_numbers", account_numbers);
    //on finit par retourner le ptree.
    return pt;
}