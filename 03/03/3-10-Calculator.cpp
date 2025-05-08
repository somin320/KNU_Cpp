#include <iostream>
using namespace std;

class Add {
	int a, b;
public:
	void setValue(int x, int y) { a = x, b = y; }
	int calculate() { return a + b; }
};

class Sub {
	int a, b;
public:
	void setValue(int x, int y) { a = x, b = y; }
	int calculate() { return a - b; }
};

class Mul {
	int a, b;
public:
	void setValue(int x, int y) { a = x, b = y; }
	int calculate() { return a * b; }
};

class Div {
	int a, b;
public:
	void setValue(int x, int y) { a = x, b = y; }
	int calculate() { return a / b; }
};

int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;
	int p, q;
	string way;
	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> p >> q >> way;
		if (way == "+") {
			a.setValue(p, q);
			cout << a.calculate() << endl;
		}
		else if (way == "-") {
			s.setValue(p, q);
			cout << s.calculate() << endl;
		}
		else if (way == "*") {
			m.setValue(p, q);
			cout << m.calculate() << endl;
		}
		else if (way == "/") {
			d.setValue(p, q);
			cout << d.calculate() << endl;
		}
	}
}