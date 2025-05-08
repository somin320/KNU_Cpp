#include <iostream>
#include<string>
using namespace std;

class Date {
private:
	int year, month, day;
public:
	Date(int a, int b, int c);
	Date(string d);
	int getYear(), getMonth(), getDay();
	void show();
};

Date::Date(int a, int b, int c) {
	year = a;
	month = b;
	day = c;
}

Date::Date(string d) {
	int f = d.find('/');
	int s = d.find('/', f + 1);

	year = stoi(d.substr(0, f));
	month = stoi(d.substr(f + 1, s - f - 1));
	day = stoi(d.substr(s + 1));
}

void Date::show() {
	cout << year << "³â" << month << "¿ù" << day << "ÀÏ" << endl;
}

int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}