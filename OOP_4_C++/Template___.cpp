#include <iostream>
#include <vector>
#include <string>
#include <iterator>

class Client {
private:
	std::string _name;
	int _id;
	//static std::vector<Client*>_clients;
	void ShowClient() {
		std::cout << "Name: " << _name << '\n';
		std::cout << "Id: " << _id << '\n';
	}
public:
	Client(std::string name, int id, std::vector<Client*>& clients) : _name(name), _id(id) {
	//	_clients.push_back(this);
		clients.push_back(this);
	}
	static void ShowClients(std::vector<Client*>&clients) { // Static - необходимо для того чтобы вызвать метод без объекта класса
		for (const auto& it : clients)
			it->ShowClient();
	}
};
//std::vector<Client*>Client::_clients;
int main() {
	setlocale(LC_ALL, "Ru");
	std::vector<Client*>clients;
	Client* client1 = new Client("John", 20, clients);
	Client* client2 = new Client("Alex", 22, clients);
	Client* client3 = new Client("Bob", 25, clients);
	//// client->ShowClient();
	Client::ShowClients(clients);





	return 0;
}