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
            cout << "������ �����ϰų� ��ũ�� �����Ͽ� ����� �� �����ϴ�." << endl;
        }
        else {
            availableCount -= pages;
            ink -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
    }
    void show() override {
        cout << "��ũ�� : " << model << ", " << manufacturer
            << ", ���� ���� " << availableCount
            << ", ���� ��ũ " << availableInk()
            << ", �μ� �ż� " << printedCount << endl;
    }
};

class LaserPrinter : public Printer {
protected:
    int toner{ 20 };
public:
    LaserPrinter() {
        model = "SCX-6x45";
        manufacturer = "�Ｚ����";
        availableCount = 3;
    }
    int availableToner() const {
        return toner;
    }
    void print(int pages) override {
        if (availableCount < pages || toner < pages) {
            cout << "������ �����ϰų� ��ʰ� �����Ͽ� ����� �� �����ϴ�." << endl;
        }
        else {
            availableCount -= pages;
            toner -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
    }
    void show() override {
        cout << "������ : " << model << ", " << manufacturer
            << ", ���� ���� " << availableCount
            << ", ���� ��� " << availableToner()
            << ", �μ� �ż� " << printedCount << endl;
    }
};

int main() {
    cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����." << endl;
    InkjetPrinter inkjet;
    LaserPrinter laser;
    inkjet.show();
    laser.show();
    int choice, count;
    char yORn;
    while (true) {
        cout << "������ (1: ��ũ��, 2: ������)�� �ż� �Է� >> ";
        cin >> choice >> count;

        if (choice == 1) {
            inkjet.print(count);
        }
        else if (choice == 2) {
            laser.print(count);
        }
        else {
            cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���." << endl;
            continue;
        }
        inkjet.show();
        laser.show();
        while (true) {
            cout << "��� ����Ʈ �Ͻðڽ��ϱ�? (y/n) >> ";
            cin >> yORn;
            if (yORn == 'y') break;
            else if (yORn == 'n') return 0;
            else cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���." << endl;
        }
    }
}