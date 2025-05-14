#include <iostream>
#include <string>
using namespace std;

class Seat {
    string name;
public:
    Seat(string name = "---") { this->name = name; }
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};

class Schedule {
    int seatSize;
    string time;
    Seat* seat;
public:
    Schedule(string time = "") {
        this->time = time;
        this->seatSize = 8;
        seat = new Seat[this->seatSize];
    }
    void setTime(string time) { this->time = time; }
    string getTime() { return time; }
    void book(int index, string name) { seat[index].setName(name); }
    void cancelBook(int index) { seat[index].setName("---"); }
    void show() {
        cout << time;
        for (int i = 0; i < seatSize; i++)
            cout << '\t' << seat[i].getName();
        cout << endl;
    }
};

class Console {
public:
    static int getMenu() {
        int select;
        cout << "����:1, ���:2, ����:3, ������:4 >> ";
        cin >> select;
        cin.ignore();
        return select;
    }
    static int getTime() {
        int select;
        cout << "07��:1, 12��:2, 17��:3 >> ";
        cin >> select;
        cin.ignore();
        return select - 1;
    }
    static int getSeatNum() {
        int select;
        cout << "�¼���ȣ >> "; cin >> select;
        cin.ignore();
        return select - 1;
    }
    static string getName() {
        string name;
        cout << "�̸� �Է� >> "; getline(cin, name);
        return name;
    }
};

class AirlineBook {
    Schedule* schedule;
    int scheduleSize;
public:
    AirlineBook() {
        this->scheduleSize = 3;
        this->schedule = new Schedule[this->scheduleSize];
        schedule[0].setTime("07��");
        schedule[1].setTime("12��");
        schedule[2].setTime("17��");
    }
    void book(int time, int index, string name) { schedule[time].book(index, name); }
    void cancel(int time, int index) { schedule[time].cancelBook(index); }
    void show(int time) { schedule[time].show(); }
};

class AirlineBookManager {
    AirlineBook* AB;
    int seatNum;
    string name;
    void book() {
        int time = Console::getTime();
        AB->show(time);
        seatNum = Console::getSeatNum();
        name = Console::getName();
        AB->book(time, seatNum, name);
    }
    void cancel() {
        int time = Console::getTime();
        AB->show(time);
        seatNum = Console::getSeatNum();
        name = Console::getName();
        AB->cancel(time, seatNum);
    }
    void show() {
        for (int i = 0; i < 3; i++)
            AB->show(i);
    }
public:
    AirlineBookManager() : AB(new AirlineBook()), seatNum(0) {}
	~AirlineBookManager() { delete AB; }
    void run() {
        cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ�. *****" << endl;
        int flag = true;
        while (flag) {
            switch (Console::getMenu()) {
            case 1:
                book();
                break;
            case 2:
                cancel();
                break;
            case 3:
                show();
                break;
            case 4:
                flag = false;
                break;
            default:
                cout << "�ٽ� �Է��ϼ���" << endl;
                break;
            }
            cout << endl;
        }
        cout << "���� �ý����� �����մϴ�." << endl;
    }
};

int main() {
    AirlineBookManager ABM;
    ABM.run();
}