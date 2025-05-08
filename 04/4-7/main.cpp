#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int r);
	double getArea();
};

void Circle::setRadius(int r){
	radius = r;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle* circle[3];
	int* p[3] = { new int(1), new int(2), new int(3) };

	for (int i = 0; i < 3; i++) {
		cout << "�� " << i + 1 << "�� ������ >>";
		cin >> *p[i];

		circle[i] = new Circle;
		circle[i]->setRadius(*p[i]);
	}

	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (circle[i]->getArea() > 100) {
			count++;
		}
	}

	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�" << endl;

	for (int i = 0; i < 3; i++) {
		delete p[i];
	}

	return 0;
}