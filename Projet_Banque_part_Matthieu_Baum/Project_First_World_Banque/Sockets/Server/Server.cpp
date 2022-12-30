#include <iostream>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

//permet de lire le message envoyé en string
string read_(tcp::socket& socket) {
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    //transforme le message en string
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}
//permet d'envoyé un message.
void send_(tcp::socket& socket, const string& message) {
    const string msg = message + "\n";
    //le message s'envoi.
    boost::asio::write(socket, boost::asio::buffer(message));
}

//transforme un arbre en string pour pouvoir le transférer à la Base de donnée
string parse(ptree pt) {

    //on rajoute à un string tout les éléments de notre base de données pour pouvoir l'envoyé au server
    string result = pt.get_child("Number").data() + "²";
    result += (pt.get_child("Name").data() + "²");
    result += (pt.get_child("mdp").data() + "²");
    result += (pt.get_child("Adresse").data() + "²");
    result += (pt.get_child("genre").data() + "²");
    result += (pt.get_child("Prenom").data() + "²");

    //on rajoute au string les numéraux de compte et pour les différencier on les sépare par des °
    for (ptree::value_type& pt_account : custom.get_child("Account_numbers"))
    {
        result += pt_account.second.get_value<int>());
        result += "°";

    }
    // on return le string qui pourra être envoyé au serveur pour la sauvegarde.
    return result;


}

int main() {
    boost::asio::io_service io_service;
    //attend une connection
    tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 3673));
    //créeer le socket
    tcp::socket socket_(io_service);
    acceptor_.accept(socket_);
    //récupére les données envoyé  la dans notre cas un string
    string message = read_(socket_);
    cout << message << endl;
    send_(socket_, "Le serveur fonctionne!!!!!");
    return 0;
}