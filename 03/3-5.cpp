#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
	int next();
	int nextInRange(int a, int b);
	Random();
	int n;
};

Random::Random() {
	this -> n = 0;
}

int Random::next() {
	this -> n = rand();
	return(this->n);
}

int Random::nextInRange(int a, int b) {
	this -> n = rand() % (b - a + 1) + a; 
	return(this->n);
}

int main() {
	Random r;
	srand(time(NULL));
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}