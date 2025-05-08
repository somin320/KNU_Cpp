#include <iostream>
using namespace std;

class Oval {
private:
	int width, height;
public:
	Oval() : width(0), height(0) {}
	Oval(int a, int b);
	int getWidth(), getHeight();
	void set(int w, int h);
	void show();
};

Oval::Oval(int a, int b) {
	width = a;
	height = b;
}

int Oval::getWidth() {
	return width;
}

int Oval::getHeight() {
	return height;
}

void Oval::set(int w, int h) {
	width = w;
	height = h;
}

void Oval::show() {
	cout << "width = " << width << ", height = " << height << "\n";
}

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;
	cout << "Oval ¼Ò¸ê : width = " << b.getWidth() << ", height = " << b.getHeight() << endl;
	cout << "Oval ¼Ò¸ê : width = " << 10 << ", height = " << 20 << endl;
}