#include "../Class/Customer_for_JSON.hpp"

int main(int argc, char** argv)
{
    ptree pt_write;
    ptree pt_accounts;

    try
    {
        Client customer1(101, "77 rue de Messines Verlinghem", "Matthieu", "Baum",
            "Fresh77", { 10000, 10001 });

        Client customer3(100, "77 rue de mortadelle Lompet", "Matt", "Baum",
            "pattateTE", { 100890, 10089 });

        Client customer6(100, "14 rue du bois", "Paulo", "Marco",
            "Frite45", { 10321, 10009 });


        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer1) });
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer3) });
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer6) });
        pt_write.add_child("Customers", pt_accounts);

        std::ofstream file_out("../out/build/x64-Debug/Boost_JSON/DB_Client.json");
        write_json(file_out, pt_write);
        file_out.close();

        std::ifstream file_in("../out/build/x64-Debug/Boost_JSON/DB_Client.json");
        read_json(file_in, pt_write);
        file_in.close();

        for (ptree::value_type& customer : pt_write.get_child("Customers"))
        {
            auto custom = get_a_customer_from_a_ptree(customer.second);

            cout << custom.Get_num() << endl;
            cout << custom.Get_adresse() << endl;
            cout << custom.Get_prenom() << endl;
            cout << custom.Get_nom() << endl;
            cout << custom.Get_mdp() << endl;
            cout << (custom.Get_num_client())[0] << endl;
        }
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }
}