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
    cout << "이름과 전화 번호를 입력해 주세요" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "사람 " << i + 1 << " >> ";
        cin >> name >> tel;
        persons[i].set(name, tel);
    }

    cout << "모든 사람의 이름은 ";
    for (int i = 0; i < 3; i++) {
        cout << persons[i].getName() << " ";
    }
    cout << endl;

    cout << "전화번호 검색합니다. 이름을 입력하세요>>";
    cin >> find;

    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (persons[i].getName() == find) {
            cout << "전화번호는 " << persons[i].getTel() << endl;
            found = true;
            break;
        }
    }

    return 0;
}