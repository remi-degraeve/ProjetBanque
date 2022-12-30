#include "Customer_for_JSON.hpp"
#include "Interface_Projet.hpp"
#include "Interface2_Projet.hpp"


#include <iostream>
using std::stoi;

wxIMPLEMENT_APP(MyApp);




bool MyApp::OnInit() //ouverture de la fenêtre acceuil
{
    MyFrame* frame_acc = new MyFrame("Banque Agency", wxPoint(30, 30), wxSize(800, 600));
    frame_acc->accueil();
    frame_acc->Show(true);
    return true;
}


MyFrame::MyFrame(const wxString& titre, const wxPoint& point, const wxSize& taille){
   


}

void MyFrame::connexion() {

    /// Création du wxBoxSizer horizontal
    wxBoxSizer* sizer_horizontal = new wxBoxSizer(wxHORIZONTAL);
    // Affectation du wxBoxSizer horizontal à la fenêtre
    SetSizer(sizer_horizontal);

    // Création du wxBoxSizer vertical pour la partie de droite
    wxBoxSizer* sizer_vertical = new wxBoxSizer(wxVERTICAL);
    // On l'ajoute au premier wxBoxSizer
    sizer_horizontal->Add(sizer_vertical, wxID_ANY, wxALL | wxEXPAND, 0);

    // Création de la zone du bas pour la partie de droite
    zone4 = new wxPanel(this);
    // Affectation de la couleur bleue à cette zone
    zone4->SetBackgroundColour(*wxWHITE);
    // Ajout de cette zone au sizer vertical
    sizer_vertical->Add(zone4, wxID_ANY, wxALL | wxEXPAND, 30);

    wxFont myFont1(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    labelrmp = new wxStaticText(zone4, wxID_ANY, "A remplir :", wxPoint(10, 10));
    labelrmp->SetFont(myFont1);

    labelNom1 = new wxStaticText(zone4, wxID_ANY, "Nom :", wxPoint(275, 35));
    labelNom1->SetFont(myFont1);

    m_txtNom = new wxTextCtrl(zone4, ID_TXT_NOM, _T(""), wxPoint(275, 60), wxSize(200, 25));


    labelPrn = new wxStaticText(zone4, wxID_ANY, "Prénom :", wxPoint(275, 100));
    labelPrn->SetFont(myFont1);

    m_txtPrenom = new wxTextCtrl(zone4, ID_TXT_PRENOM, _T(""), wxPoint(275, 125), wxSize(200, 25));


    labelmdp1 = new wxStaticText(zone4, wxID_ANY, "Mot de passe :", wxPoint(275, 165));
    labelmdp1->SetFont(myFont1);

    m_txtmdp2 = new wxTextCtrl(zone4, ID_TXT_MDP2, _T(""), wxPoint(275, 190), wxSize(200, 25));


    labelAdr = new wxStaticText(zone4, wxID_ANY, "Adresse :", wxPoint(275, 230));
    labelAdr->SetFont(myFont1);

    m_txtAdresse = new wxTextCtrl(zone4, ID_TXT_ADRESSE, _T(""), wxPoint(275, 255), wxSize(200, 25));


    labelbnq = new wxStaticText(zone4, wxID_ANY, "Banque :", wxPoint(275, 295));
    labelbnq->SetFont(myFont1);

    m_txtbnq = new wxTextCtrl(zone4, ID_TXT_BNQ, _T(""), wxPoint(275, 315), wxSize(200, 25));


    menuBouton = new wxButton(zone4, ID_BTN_RETOUR, "Retour", wxPoint(225, 400), wxSize(75, 35));
    menuBouton1 = new wxButton(zone4, ID_BTN_VALIDER, "Enregistrer", wxPoint(475, 400), wxSize(75, 35));
    menuBouton1->Disable();



    Connect(ID_BTN_RETOUR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnRetour));
    Connect(ID_BTN_VALIDER, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnSaveCustomers, MyFrame::OnBtnValiderClicked));



    Connect(ID_TXT_NOM, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::Oncacher));
    Connect(ID_TXT_PRENOM, ID_TXT_MDP2, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::Oncacher));
    Connect(ID_TXT_ADRESSE, ID_TXT_BNQ, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::Oncacher));


    CreateStatusBar();
    SetStatusText("Bienvenue à PNB Junia!");


}


void MyFrame::accueil(){

    /// Création du wxBoxSizer horizontal
    wxBoxSizer* sizer_horizontal = new wxBoxSizer(wxHORIZONTAL);
    // Affectation du wxBoxSizer horizontal à la fenêtre
    SetSizer(sizer_horizontal);

    // Création du wxBoxSizer vertical pour la partie de droite
    wxBoxSizer* sizer_vertical = new wxBoxSizer(wxVERTICAL);
    // On l'ajoute au premier wxBoxSizer
    sizer_horizontal->Add(sizer_vertical, wxID_ANY, wxALL | wxEXPAND, 0);

    // Création de la zone du bas pour la partie de droite
    wxPanel* zone4 = new wxPanel(this);
    // Affectation de la couleur bleue à cette zone
    zone4->SetBackgroundColour(*wxWHITE);
    // Ajout de cette zone au sizer vertical
    sizer_vertical->Add(zone4, wxID_ANY, wxALL | wxEXPAND, 30);


    wxFont myFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont myFont1(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    labelNom = new wxStaticText(zone4, wxID_ANY, "PNB JUNIA", wxPoint(325, 75));
    labelNom->SetFont(myFont);

    labelNum = new wxStaticText(zone4, wxID_ANY, "ID client :", wxPoint(275, 150));
    labelNum->SetFont(myFont1);

    m_txtNum = new wxTextCtrl(zone4, wxID_ANY, _T(""), wxPoint(275, 175), wxSize(200, 25));


    labelmdp = new wxStaticText(zone4, wxID_ANY, "Mot de passe :", wxPoint(275, 250));
    labelmdp->SetFont(myFont1);

    m_txtmdp1 = new wxTextCtrl(zone4, wxID_ANY, _T(""), wxPoint(275, 275), wxSize(200, 25));


    menuBouton2 = new wxButton(zone4, ID_CONNEXION, "Connexion", wxPoint(225, 350), wxSize(75, 35));
    menuBouton3 = new wxButton(zone4, ID_BTN_INSCRIPTION, "Inscription", wxPoint(475, 350), wxSize(75, 35));

    Connect(ID_TXT_NOM, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::Oncacher));
    Connect(ID_TXT_PRENOM, ID_TXT_MDP2, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::Oncacher));
    Connect(ID_TXT_ADRESSE, ID_TXT_BNQ, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::Oncacher));

    Connect(ID_BTN_INSCRIPTION, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnInscription));
    Connect(ID_BTN_CONNEXION, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnConnexion));



    CreateStatusBar();
    SetStatusText("Bienvenue à PNB Junia!");


}


void MyFrame::compte() {

    /// Création du wxBoxSizer horizontal
    wxBoxSizer* sizer_horizontal = new wxBoxSizer(wxHORIZONTAL);
    // Affectation du wxBoxSizer horizontal à la fenêtre
    SetSizer(sizer_horizontal);

    // Création du wxBoxSizer vertical pour la partie de droite
    wxBoxSizer* sizer_vertical = new wxBoxSizer(wxVERTICAL);
    // On l'ajoute au premier wxBoxSizer
    sizer_horizontal->Add(sizer_vertical, wxID_ANY, wxALL | wxEXPAND, 0);

    // Création de la zone du bas pour la partie de droite
    wxPanel* zone4 = new wxPanel(this);
    // Affectation de la couleur bleue à cette zone
    zone4->SetBackgroundColour(*wxWHITE);
    // Ajout de cette zone au sizer vertical
    sizer_vertical->Add(zone4, wxID_ANY, wxALL | wxEXPAND, 30);


    wxFont myFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont myFont1(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);



}


void MyFrame::OnRetour(wxCommandEvent& event) {

    Hide();

    MyFrame* frame_ = new MyFrame("Banque Agency", wxPoint(30, 30), wxSize(800, 600));
    frame_->accueil();
    frame_->Show(true);

    Close();
}


void MyFrame::OnConnexion(wxCommandEvent& event) {

    std::string numm = m_txtNum->GetValue();
    std::string mdp = m_txtmdp1->GetValue();

    int num = stoi(numm);

    if(verify_connection(num, mdp) == true) {

        Hide();

        MyFrame* frame_com = new MyFrame("Banque Agency", wxPoint(30, 30), wxSize(800, 600));
        frame_com->compte();
        frame_com->Show(true);

        Close();
    }

    else {

        // Variable wxString pour le message à afficher
        wxString sMessage = _T("Données utilisateur :");

        // Ajout du nom et du prénom par la méthode des flux
        sMessage << _T("\n ID Client ou Mot de passe incorrecte \t: ");


        // Affichage du message
        wxMessageBox(sMessage, _T("Récapitulatif"));


    }

}


void MyFrame::OnInscription(wxCommandEvent& event) {

    Hide();

    MyFrame* frame_con = new MyFrame("Banque Agency", wxPoint(30, 30), wxSize(800, 600));
    frame_con->connexion();
    frame_con->Show(true);

    Close();
}

void MyFrame::OnBtnValiderClicked(wxCommandEvent& event)
{
    // Cacher la fenêtre (sans la fermer)
    Hide();

    // Variable wxString pour le message à afficher
    wxString sMessage = _T("Données utilisateur :");
    // Ajout du nom et du prénom par la méthode des flux
    sMessage << _T("\n Nom - Prénom - mot de passe \t: ") << m_txtNom->GetValue() << _T(" ") << m_txtPrenom->GetValue() << _T(" ") << m_txtmdp2->GetValue();
    sMessage << _T("\n Adresse - Banque \t: ") << m_txtAdresse->GetValue() << _T(" ") << m_txtbnq->GetValue();

    // Affichage du message
    wxMessageBox(sMessage, _T("Récapitulatif"));

    // Fermeture de la fenêtre
    Close();
}

void MyFrame::Oncacher(wxCommandEvent& event)
{
    bool bOK = true;
    if (m_txtNom->IsEmpty()) bOK = false;
    if (m_txtPrenom->IsEmpty()) bOK = false;
    if (m_txtmdp2->IsEmpty()) bOK = false;
    if (m_txtAdresse->IsEmpty()) bOK = false;
    if (m_txtbnq->IsEmpty()) bOK = false;

    if (bOK == true)
        menuBouton1->Enable();
    else
        menuBouton1->Disable();
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    int reponse = wxMessageBox(_T("Annuler le formulaire ?"), // Message à afficher
        _T("Confirmation"), // Titre de la boite de message
        wxYES_NO | wxICON_QUESTION); // Style

    if (reponse == wxYES) // Si la réponse est positive,
        Close();          // on ferme la fenêtre
}

void MyFrame::OnBtnAnnulerClicked(wxCommandEvent& event)
{
    int reponse = wxMessageBox(_T("Annuler le formulaire ?"), // Message à afficher
        _T("Confirmation"), // Titre de la boite de message
        wxYES_NO | wxICON_QUESTION); // Style

    if (reponse == wxYES) // Si la réponse est positive,
        Close();   // on ferme la fenêtre

}


void MyFrame::OnSaveCustomers(wxCommandEvent& event)
{
    auto new_customer = new My_new_Customer_dialog(this, wxID_ANY, "Ajouter customer");

    if (new_customer->ShowModal() == wxID_OK)
    {
        auto customer_number = new_customer->get_customer_number();
        auto customer_name = new_customer->get_name();
        auto customer_account_numbers = new_customer->get_account_numbers();



        long number;

        long account_numbers; // Only one at this time

        if (!customer_number.ToLong(&number))
        {
            wxMessageBox("Error number",
                "Error ", wxOK | wxICON_INFORMATION);
            return;
        }

        if (!customer_number.ToLong(&account_numbers))
        {
            wxMessageBox("Account numbers",
                "Error ", wxOK | wxICON_INFORMATION);
            return;
        }

        std::string name = std::string(customer_name);
        Customer customer(number, std::move(name), { 1000 });
        customers_.push_back(customer);
        delete new_customer;
    }

    ptree pt_write;
    ptree pt_accounts;
    try
    {
        for (auto& customer : customers_)
        {
            pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer) });
        }
        pt_write.add_child("Customers", pt_accounts);
        std::ofstream file_out("example_write_read.json");
        write_json(file_out, pt_write);
        file_out.close();
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }

    Hide();

    MyFrame* frame_ = new MyFrame("Banque Agency", wxPoint(30, 30), wxSize(800, 600));
    frame_->accueil();
    frame_->Show(true);

    Close();

}

bool verify_connection(int id_user, std::string mdp) {

    ptree pt_writ;
    ptree pt_account;
    try {
        std::ifstream file_in("../Boost_JSON/DB_Client.json");
        read_json(file_in, pt_writ);
        file_in.close();

        for (ptree::value_type& pt_accounts : pt_writ.get_child("Client")) {
            Client client = get_a_customer_from_a_ptree(pt_accounts.second);
            if (client.Get_mdp() == mdp && client.Get_num() == id_user) {
                std::cout << "authentification réussi !" << std::endl;
                return true;
            }
        }
        std::cout << "authentification raté ! Votre numéro de client ou votre mot de passe doit avoir une erreur." << std::endl;
        return false;
    }
    catch (std::exception& e)
    {
        // Other errors
        std::cout << "Error :" << e.what() << std::endl;
    }
}





