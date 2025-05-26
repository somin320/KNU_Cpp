#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
	string title;
	string author;
	int year;
public:
	Book() {};
	Book(string title, string author, int year) {
		this->title = title;
		this->author = author;
		this->year = year;
	}
	void set(string title, string author, int year) {
		this->title = title;
		this->author = author;
		this->year = year;
	}
	string getAuthor() { return author; }
	int getYear() { return year; }
	void show();
};

void Book::show() {
	cout << year << "년도, " << title << ", " << author << endl;
}

class BookManager {
	vector<Book> v;
	void searchByAuthor();
	void searchByYear();
	void bookIn();
public:
	void run();
};

void BookManager::searchByAuthor() {
	cout << "검색하고자 하는 저자 이름을 입력하세요>>";
	string author;
	getline(cin, author);
	for (int i = 0; i < v.size(); i++) {
		Book b = v[i];
		if (b.getAuthor() == author)
			b.show();
	}
}

void BookManager::searchByYear() {
	cout << "검색하고자 하는 년도를 입력하세요>>";
	int year;
	cin >> year; cin.ignore();
	for (int i = 0; i < v.size(); i++) {
		Book b = v[i];
		if (b.getYear() == year)
			b.show();
	}
}

void BookManager::bookIn() {
	string title, author;
	int year;
	Book b;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
	while (true) {
		cout << "년도>>";
		cin >> year; cin.ignore();
		if (year == -1)
			break;
		cout << "책이름>>";
		getline(cin, title);
		cout << "저자>>";
		getline(cin, author);
		b.set(title, author, year);
		v.push_back(b);
	}
	cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;
}

void BookManager::run() {
	bookIn();
	searchByAuthor();
	searchByYear();
}

int main() {
	BookManager man;
	man.run();
}