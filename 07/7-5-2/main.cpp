#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
	friend Color& operator + (Color& A, Color& C);
	friend int operator == (Color A, Color B);
};
Color& operator + (Color& A, Color& C) {
	Color B;
	B.red = C.red + A.red;
	B.green = C.green + A.green;
	B.blue = C.blue + A.blue;
	return B;
}
int operator == (Color A, Color B) {
	if (B.red == A.red && B.green == A.green && B.blue == A.blue) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";

}