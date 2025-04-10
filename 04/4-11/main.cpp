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
        cout << "에스프레소 드세요" << endl;
    }
    else {
        cout << "원료가 부족합니다" << endl;
    }
}

void CoffeeVendingMachine::selectAmericano() {
    if (item[0].getSize() >= 1 && item[1].getSize() >= 2) {
        item[0].consume();
        item[1].consume();
        item[1].consume();
        cout << "아메리카노 드세요" << endl;
    }
    else {
        cout << "원료가 부족합니다" << endl;
    }
}

void CoffeeVendingMachine::selectSugarCoffee() {
    if (item[0].getSize() >= 1 && item[1].getSize() >= 2 && item[2].getSize() >= 1) {
        item[0].consume();
        item[1].consume();
        item[1].consume();
        item[2].consume();
        cout << "설탕커피 드세요" << endl;
    }
    else {
        cout << "원료가 부족합니다" << endl;
    }
}

void CoffeeVendingMachine::show() {
    cout << "커피 " << item[0].getSize() << ", 물 " << item[1].getSize() << ", 설탕 " << item[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
    cout << "***** 커피자판기를 작동합니다. *****" << endl;
    while (true) {
        int num;
        cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
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