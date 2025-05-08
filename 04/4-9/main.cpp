#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

void Person::set(string name, string tel) {
    this->name = name;
    this->tel = tel;
}

int main() {
    Person persons[3];
    string name, tel, find;
    cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "��� " << i + 1 << " >> ";
        cin >> name >> tel;
        persons[i].set(name, tel);
    }

    cout << "��� ����� �̸��� ";
    for (int i = 0; i < 3; i++) {
        cout << persons[i].getName() << " ";
    }
    cout << endl;

    cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
    cin >> find;

    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (persons[i].getName() == find) {
            cout << "��ȭ��ȣ�� " << persons[i].getTel() << endl;
            found = true;
            break;
        }
    }

    return 0;
}