#include <iostream>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }
	friend Book& operator += (Book& book, int adder);
	friend Book& operator -= (Book& book, int adder);
};
Book& operator += (Book& book , int adder) {
	book.price = book.price + adder;
	return book;
}
Book& operator -= (Book& book, int adder) {
	book.price = book.price - adder;
	return book;
}
int main() {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}
// +=, -= ������ �Լ��� Book Ŭ������ ��� �Լ���, Ŭ���� �ܺ� �Լ��� �����϶�