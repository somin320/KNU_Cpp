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
        cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
        string name;
        int radius;
        cin >> name >> radius;
        p[i].setCircle(name, radius);
    }
}

void CircleManager::searchByName() {
    cout << "검색하고자 하는 원의 이름 >> ";
    string name;
    cin >> name;
    for (int i = 0; i < size; i++) {
        if (p[i].getName() == name) {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
            return;
        }
    }
}

void CircleManager::searchByArea() {
    cout << "최소 면적을 정수로 입력하세요 >> ";
    int minArea;
    cin >> minArea;
    cout << minArea << "보다 큰 원을 검색합니다." << endl;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (p[i].getArea() > minArea) {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
            found = true;
        }
    }
    if (found) cout << endl;
    else cout << "조건에 맞는 원이 없습니다." << endl;
}

int main() {
    cout << "원의 개수 >> ";
    int size;
    cin >> size;

    CircleManager cm(size);
    cm.searchByName();
    cm.searchByArea();

    return 0;
}