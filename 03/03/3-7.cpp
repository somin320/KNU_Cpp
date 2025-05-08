#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class EvenRandom {
public:
	int next();
	int nextInRange(int a, int b);
	EvenRandom();
	int n;
};

EvenRandom::EvenRandom() {
	this->n = 0;
}

int EvenRandom::next() {
	int maxEven = (RAND_MAX % 2 == 0) ? RAND_MAX : RAND_MAX - 1;
	int range = maxEven / 2 + 1;
	this->n = (rand() % range) * 2;
	return(this->n);
}

int EvenRandom::nextInRange(int a, int b) {
	this->n = rand() % (b - a - 3) * 2;
	return(this->n);
}

int main() {
	EvenRandom r;
	srand((unsigned)time(0));
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 9);
		cout << (n + 3) << ' ';
	}
	cout << endl;
}