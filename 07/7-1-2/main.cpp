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
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
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
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}
// +=, -= 연산자 함수를 Book 클래스의 멤버 함수로, 클래스 외부 함수로 구현하라