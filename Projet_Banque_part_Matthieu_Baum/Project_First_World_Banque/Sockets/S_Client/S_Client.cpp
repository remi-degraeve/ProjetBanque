#include <iostream>
#include <boost/asio.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

int main() {
    boost::asio::io_service io_service;
    //création du sockets
    tcp::socket socket(io_service);
    //connection au port 1234 du server d'ip 127.0.0.1
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    //message à envoyé au serveur
    const string msg = "Ce message est un test!\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    if (!error) {
        cout << "Ce message est encore un test!" << endl;
    }
    else {
        cout << "send failed: " << error.message() << endl;
    }
    //récupére la réponse du serveur
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if (error && error != boost::asio::error::eof) {
        cout << "receive failed: " << error.message() << endl;
    }
    else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << data << endl;
    }
    return 0;
}