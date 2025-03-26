#include <iostream>
#include <string>
using namespace std;

class Account {
public:
	string name;
	int id, balance;
	Account(string b, int c, int d);
	string getOwner();
	void deposit(int a);
	int withdraw(int a), inquiry();
};

Account::Account(string b, int c, int d) {
	name = b;
	id = c;
	balance = d;
}

string Account::getOwner() {
	return name;
}

void Account::deposit(int a) {
	balance += a;
}

int Account::withdraw(int a) {
	return balance -= a;
}

int Account::inquiry() {
	return balance;
}

int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
}