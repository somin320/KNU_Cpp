#include <iostream>
#include <string>
using namespace std;

class Circle {
    int radius;
    string name;
public:
    void setCircle(string name, int radius) {
        this->name = name;
        this->radius = radius;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
    string getName() {
        return name;
    }
};

class CircleManager {
    Circle* p;
    int size;
public:
    CircleManager(int size);
    ~CircleManager() { delete[] p; }
    void searchByName();
    void searchByArea();
};

CircleManager::CircleManager(int size) : size(size) {
    p = new Circle[size];
    for (int i = 0; i < size; i++) {
        cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
        string name;
        int radius;
        cin >> name >> radius;
        p[i].setCircle(name, radius);
    }
}

void CircleManager::searchByName() {
    cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
    string name;
    cin >> name;
    for (int i = 0; i < size; i++) {
        if (p[i].getName() == name) {
            cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
            return;
        }
    }
}

void CircleManager::searchByArea() {
    cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
    int minArea;
    cin >> minArea;
    cout << minArea << "���� ū ���� �˻��մϴ�." << endl;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (p[i].getArea() > minArea) {
            cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", ";
            found = true;
        }
    }
    if (found) cout << endl;
    else cout << "���ǿ� �´� ���� �����ϴ�." << endl;
}

int main() {
    cout << "���� ���� >> ";
    int size;
    cin >> size;

    CircleManager cm(size);
    cm.searchByName();
    cm.searchByArea();

    return 0;
}