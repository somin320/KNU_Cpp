#include <iostream>
using namespace std;

class Menus {
	int id;
	string name;
	string address;
	string tel;
	char gender;
public:
	Menus();
	int display();
	void insertclients(int newId, string newName, string newTel, string newAddress, char newGender);
	void inputClientDetails();
};

Menus::Menus() {}

int Menus::display() {
	int selection;
	cout << "menu" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. insert clients" << endl;
	cout << "2. delete clients" << endl;
	cout << "3. display clients" << endl;
	cout << "4. list clients" << endl;
	cout << "5. reference" << endl;
	cout << "--------------------------------" << endl;
	cout << "please input selections (1~5): ";
	cin >> selection;

	return selection;
}

void Menus::insertclients(int newId, string newName, string newTel, string newAddress, char newGender) {
	this->id = newId;
	this->name = newName;
	this->tel = newTel;
	this->address = newAddress;
	this->gender = newGender;
}

void Menus::inputClientDetails() {
	int newId;
	string newName, newTel, newAddress;
	char newGender;
	cout << "Enter client ID: ";
	cin >> newId;
	cout << "Enter client name: ";
	cin >> newName;
	cout << "Enter client telephone: ";
	cin >> newTel;
	cout << "Enter client address: ";
	cin >> newAddress;
	cout << "Enter client gender (M/F): ";
	cin >> newGender;
	insertclients(newId, newName, newTel, newAddress, newGender);
}

int main() {
	Menus menu;
	int selection = menu.display();
	if (selection == 1) {
		int numClients;
		cout << "Enter the number of clients: ";
		cin >> numClients;

		Menus* clients = new Menus[numClients];

		for (int i = 0; i < numClients; ++i) {
			cout << "Entering details for client " << i + 1 << ":" << endl;
			clients[i].inputClientDetails();
		}

		delete[] clients;
	}
	return 0;
}