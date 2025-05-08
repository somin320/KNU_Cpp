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
	friend int operator ! (Book book);
};

int operator ! (Book book) {
	return !(book.price);
}

int main() {
	Book book("�������", 0, 50);
	if (!book) cout << "��¥��" << endl;
}