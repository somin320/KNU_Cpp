#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UI {
public:
	static int getMainMenu();
	static void getCircle(int&, string&);
	static string getCircleName();
	static void println(string = "");
	static void print(string);
	static void print(int);
};

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleVectorManager {
	enum { EDIT = 1, REMOVE = 2, PAINT = 3, EXIT = 4 };
	vector<Circle*> v;
	void edit();
	void remove();
	void paint();
public:
	CircleVectorManager();
	~CircleVectorManager();
	void run();
};

CircleVectorManager::CircleVectorManager() {}
CircleVectorManager::~CircleVectorManager() {}

void CircleVectorManager::edit() {
	int radius;
	string name;
	UI::getCircle(radius, name);
	v.push_back(new Circle(radius, name));
}

void CircleVectorManager::remove() {
	string name;
	name = UI::getCircleName();
	vector<Circle*>::iterator it = v.begin();
	while (it != v.end()) {
		Circle* p = *it;
		if (p->getName() == name) {
			it = v.erase(it);
			delete p;
		}
		else it++;
	}
}

void CircleVectorManager::paint() {
	vector<Circle*>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		Circle* p = *it;
		UI::println(p->getName());
	}
	UI::println();
}

void CircleVectorManager::run() {
	UI::println("���� �����ϰ� �����ϴ� ���α׷��Դϴ�.");
	while (true) {
		int menu = UI::getMainMenu();
		switch (menu) {
		case EDIT:
			edit(); break;
		case REMOVE:
			remove(); break;
		case PAINT:
			paint(); break;
		case EXIT:
			return;
		default:
			UI::println("��� ���� ����");
		}
	}
}

int UI::getMainMenu() {
	cout << "����:1, ����:2, ��κ���:3. ����:4 >> ";
	int menu;
	cin >> menu;
	return menu;
}

void UI::getCircle(int& radius, string& name) {
	cout << "�����ϰ��� �ϴ� ���� �������� �̸��� >> ";
	cin >> radius >> name;
}

string UI::getCircleName() {
	cout << "�����ϰ��� �ϴ� ���� �̸��� >> ";
	string name;
	cin >> name;
	return name;
}

void UI::println(string msg) { cout << msg << endl; }

void UI::print(string msg) { cout << msg; }

void UI::print(int msg) { cout << msg; }

int main() {
	CircleVectorManager cvm;
	cvm.run();
}