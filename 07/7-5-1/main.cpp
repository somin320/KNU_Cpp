#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
	Color& operator + (Color A) {
		red = red + A.red;
		green = green + A.green;
		blue = blue + A.blue;
		return *this;
	}
	int operator == (Color A) {
		if (red == A.red && green == A.green && blue == A.blue) {
			return 1;
		}
		else {
			return 0;
		}
	}
};

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "����� ����";
	else
		cout << "����� �ƴ�";

}