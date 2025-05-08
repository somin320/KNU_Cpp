#include <iostream>
using namespace std;

class Container {
private:
    int size;
public:
    Container() { size = 10; }
    void fill() { size = 10; }
    void consume() { size = size - 1; }
    int getSize() { return size; }
};

class CoffeeVendingMachine {
    Container item[3];
    void fill();
    void selectEspresso();
    void selectAmericano();
    void selectSugarCoffee();
    void show();
public:
    void run();
};

void CoffeeVendingMachine::fill() {
    for (int i = 0; i < 3; i++)
        item[i].fill();
    show();
}

void CoffeeVendingMachine::selectEspresso() {
    if (item[0].getSize() >= 1 && item[1].getSize() >= 1) {
        item[0].consume();
        item[1].consume();
        cout << "���������� �弼��" << endl;
    }
    else {
        cout << "���ᰡ �����մϴ�" << endl;
    }
}

void CoffeeVendingMachine::selectAmericano() {
    if (item[0].getSize() >= 1 && item[1].getSize() >= 2) {
        item[0].consume();
        item[1].consume();
        item[1].consume();
        cout << "�Ƹ޸�ī�� �弼��" << endl;
    }
    else {
        cout << "���ᰡ �����մϴ�" << endl;
    }
}

void CoffeeVendingMachine::selectSugarCoffee() {
    if (item[0].getSize() >= 1 && item[1].getSize() >= 2 && item[2].getSize() >= 1) {
        item[0].consume();
        item[1].consume();
        item[1].consume();
        item[2].consume();
        cout << "����Ŀ�� �弼��" << endl;
    }
    else {
        cout << "���ᰡ �����մϴ�" << endl;
    }
}

void CoffeeVendingMachine::show() {
    cout << "Ŀ�� " << item[0].getSize() << ", �� " << item[1].getSize() << ", ���� " << item[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
    cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
    while (true) {
        int num;
        cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>> ";
        cin >> num;
        switch (num) {
        case 1:
            selectEspresso();
            break;
        case 2:
            selectAmericano();
            break;
        case 3:
            selectSugarCoffee();
            break;
        case 4:
            show();
            break;
        case 5:
            fill();
            break;
        }
    }
}

int main() {
    CoffeeVendingMachine machine;
    machine.run();
    return 0;
}