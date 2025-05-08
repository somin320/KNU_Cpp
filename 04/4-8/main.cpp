#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int r);
	double getArea();
};

void Circle::setRadius(int r) {
	radius = r;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	int n = 0;
	cout << "원의 개수 >>";
	cin >> n;

	Circle** circle = new Circle * [n]; 
	int* p = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 반지름 >>";
		cin >> p[i];

		circle[i] = new Circle;
		circle[i]->setRadius(p[i]);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (circle[i]->getArea() > 100) {
			count++;
		}
	}

	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;

	for (int i = 0; i < n; i++) {
		delete circle[i];
	}
	delete[] circle;
	delete[] p;

	return 0;
}