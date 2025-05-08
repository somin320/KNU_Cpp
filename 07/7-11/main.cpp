#include <iostream>
using namespace std;

class Stack {
	int stack[100] = { 0 };
	int top = -1;
public:
	Stack& operator << (int r) {
		stack[++top] = r;
		return *this;
	}
	Stack& operator >> (int &r) {
		r = stack[top--];
		return *this;
	}
	bool operator !() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
};


int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true)
	{
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}