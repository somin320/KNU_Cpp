#include <iostream>
using namespace std;

class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;
    Printer() : printedCount(0), availableCount(0) {}
public:
    virtual ~Printer() {}
    virtual void print(int pages) = 0;
    virtual void show() = 0;
};

class InkjetPrinter : public Printer {
protected:
    int ink{ 10 };
public:
    InkjetPrinter() {
        model = "Officejet V40";
        manufacturer = "HP";
        availableCount = 5;
    }
    int availableInk() const {
        return ink;
    }
    void print(int pages) override {
        if (availableCount < pages || ink < pages) {
            cout << "용지가 부족하거나 잉크가 부족하여 출력할 수 없습니다." << endl;
        }
        else {
            availableCount -= pages;
            ink -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }
    void show() override {
        cout << "잉크젯 : " << model << ", " << manufacturer
            << ", 남은 종이 " << availableCount
            << ", 남은 잉크 " << availableInk()
            << ", 인쇄 매수 " << printedCount << endl;
    }
};

class LaserPrinter : public Printer {
protected:
    int toner{ 20 };
public:
    LaserPrinter() {
        model = "SCX-6x45";
        manufacturer = "삼성전자";
        availableCount = 3;
    }
    int availableToner() const {
        return toner;
    }
    void print(int pages) override {
        if (availableCount < pages || toner < pages) {
            cout << "용지가 부족하거나 토너가 부족하여 출력할 수 없습니다." << endl;
        }
        else {
            availableCount -= pages;
            toner -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }
    void show() override {
        cout << "레이저 : " << model << ", " << manufacturer
            << ", 남은 종이 " << availableCount
            << ", 남은 토너 " << availableToner()
            << ", 인쇄 매수 " << printedCount << endl;
    }
};

int main() {
    cout << "현재 작동중인 2대의 프린터는 아래와 같다." << endl;
    InkjetPrinter inkjet;
    LaserPrinter laser;
    inkjet.show();
    laser.show();
    int choice, count;
    char yORn;
    while (true) {
        cout << "프린터 (1: 잉크젯, 2: 레이저)와 매수 입력 >> ";
        cin >> choice >> count;

        if (choice == 1) {
            inkjet.print(count);
        }
        else if (choice == 2) {
            laser.print(count);
        }
        else {
            cout << "입력이 잘못되었습니다. 다시 입력해주세요." << endl;
            continue;
        }
        inkjet.show();
        laser.show();
        while (true) {
            cout << "계속 프린트 하시겠습니까? (y/n) >> ";
            cin >> yORn;
            if (yORn == 'y') break;
            else if (yORn == 'n') return 0;
            else cout << "입력이 잘못되었습니다. 다시 입력해주세요." << endl;
        }
    }
}