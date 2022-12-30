#pragma once
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/event.h>
#include <wx/valnum.h>
#include "Interface_Projet.hpp"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "Customer_for_JSON.hpp"


#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "Customer_for_JSON.hpp"
#include "Customer_for_JSON.cpp"

using namespace std;


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Customer.hpp"
#include "My_new_Customer_dialog.hpp"


enum
{
    ID_Add_Customer = 1,
    ID_Customer_field = 2,
    ID_Customers_save = 3,

    ID_ACCUEIL,
    ID_CONNEXION,
    ID_BTN_CONNEXION,
    ID_BTN_INSCRIPTION,
    ID_TXT_NUM,
    ID_TXT_MDP,

    ID_BTN_VALIDER = wxID_HIGHEST + 1,
    ID_BTN_ANNULER,
    ID_BTN_RETOUR,
    ID_BTN_EXIT,
    ID_TXT_NOM,
    ID_TXT_PRENOM,
    ID_TXT_MDP2,
    ID_TXT_ADRESSE,
    ID_TXT_BNQ
};

class MyFrame_Add_Customer : public wxFrame
{
public:
    MyFrame_Add_Customer();

private:
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
private:
    // Variables pour les contrôles
    wxPanel* zone4;
    wxStaticText* labelrmp, * labelNom1, * labelPrn, * labelmdp1, * labelAdr, * labelbnq, * labelNom, * labelNum, * labelmdp;
    wxTextCtrl* m_txtNum, * m_txtmdp1, * m_txtNom, * m_txtPrenom, * m_txtmdp2, * m_txtAdresse, * m_txtbnq;
    wxButton* menuBouton1, * menuBouton, * menuBouton2, * menuBouton3;


    std::vector<Customer> customers_;

public:

    MyFrame(const wxString& titre, const wxPoint& point, const wxSize& taille);
    void connexion();
    void accueil();
    void compte();


    void OnExit(wxCommandEvent& event);
    void OnSaveCustomers(wxCommandEvent& event);

    void Oncacher(wxCommandEvent& event);
    void OnRetour(wxCommandEvent& event);
    void OnInscription(wxCommandEvent& event);
    void OnConnexion(wxCommandEvent& event);
    void OnBtnAnnulerClicked(wxCommandEvent& event);
    void OnBtnValiderClicked(wxCommandEvent& event);

};



class Client {
private:
    int num;
    string adresse;
    string prenom;
    string nom;
    string mdp;
    vector<int> num_client;
public:
    Client(int nume, string adrese, string prnom, string ndf, string MDP, vector<int> new_num_client) :num(nume), adresse(adrese), prenom(prnom), nom(ndf), mdp(MDP), num_client(new_num_client) {}
    Client(string adrese, string prnom, string ndf, string MDP);
    int Get_num();
    string Get_adresse();
    string Get_prenom();
    string Get_nom();
    string Get_mdp();
    vector<int> Get_num_client();
    void Set_num(int new_num);
    void Set_adresse(string new_adresse);
    void Set_prenom(string new_prenom);
    void Set_nom(string new_nom);
    void Set_mdp(string new_mdp);
    void Set_num_client(int new_num_client, int num_valeur);

    void add_account_numbers_for_a_client(int id_user, int num_compte);
    ptree get_a_ptree_from_a_customer(Client& customer);
    bool verify_connection(int id_user, std::string mdp);
    Client get_a_customer_from_a_ptree(ptree& pt);
    ptree get_a_ptree_from_a_customer_values(int nume, string adrese, string prnom, string ndf, string MDP, vector<int> new_num_client);
    int get_an_amount_of_client_from_a_ptree(ptree& pt);
    ptree get_a_ptree_from_an_amount_of_client(int Num_of_clients_in_db);
};

