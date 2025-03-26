#include <iostream>
#include <string>
using namespace std;

class Integer {
public:
	int number, get();
	bool isEven();
	void set(int a);
	Integer(int a) : number(a) {};
	Integer(const string& s) : number(stoi(s)) {};
};

int Integer::get() {
	return number;
}

void Integer::set(int a) {
	number = a;
}

bool Integer::isEven() {
	return 1;
}

int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
}