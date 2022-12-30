#include "../Class/Customer_for_JSON.hpp"

int main(int argc, char** argv)
{
    ptree pt_write;
    ptree pt_accounts;

    try
    {
        Client customer1("77 rue de Messines Fortnite", "Hyppo", "Baum",
            "Fresh77");

        Client customer3("77 rue de mortadelle Lompet", "Hugo", "Visto",
            "pattateTE");

        Client customer6( "14 rue du bois", "Paulo", "Martino",
            "Frite45");
        



        std::ifstream file_in("../Boost_JSON/DB_Client.json");
        read_json(file_in, pt_write);
        file_in.close();


        /*for (ptree::value_type& cust : pt_write.get_child("Amount_of_client")) {
            auto num_two = get_an_amount_of_client_from_a_ptree(cust.second);
            cout << num_two << endl;
        }*/

        //add_account_numbers_for_a_client(3, 1209);

        for (ptree::value_type& customer : pt_write.get_child("Client"))
        {
            auto custom = get_a_customer_from_a_ptree(customer.second);

            cout << custom.Get_num() << endl;
            cout << custom.Get_adresse() << endl;
            cout << custom.Get_prenom() << endl;
            cout << custom.Get_nom() << endl;
            cout << custom.Get_mdp() << endl;
            for (int i = 0; i < (custom.Get_num_client()).size(); i++) {
                cout <<(custom.Get_num_client())[i] << endl;
            }
        }
        bool response;
        //bon mdp et id
        response = verify_connection(2, "pattateTE");
        cout << response << endl;
        //mauvais mdp
        response = verify_connection(2, "pattateT");
        cout << response << endl;
        //on rajoute au deuxième client un compte numéroté 1364
        add_account_numbers_for_a_client(2, 1364);
        
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }
}
