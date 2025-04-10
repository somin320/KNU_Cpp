#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
public:
    Person(string name) { this->name = name; }
    string getName() { return name; }
    Person() : name("") {}
};

class Family {
    Person* p;
    int size;
    string name;
public:
    Family(string name, int size) {
        this->name = name;
        this->size = size;
        p = new Person[size];
    }
    void setPerson(int index, string name) {
        if (index >= 0 && index < size) {
            p[index] = Person(name);
        }
    }
    void show() {
        cout << name << "Simpson가족은 다음과 같이 " << size << "명 입니다." << endl;
        for (int i = 0; i < size; i++) {
            cout << p[i].getName();
            if (i < size - 1)
                cout << "\t";
        }
        cout << endl;
    }
    ~Family() {
        delete[] p;
    }
};

int main() {
    Family* simpson = new Family("Simpson", 3);
    simpson->setPerson(0, "Mr. Simpson");
    simpson->setPerson(1, "Mrs. Simpson");
    simpson->setPerson(2, "Bart Simpson");
    simpson->show();
    delete simpson;
}