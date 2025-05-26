#include <iostream>
#include <string>
#include <map>
using namespace std;

class GradeManager {
	string program;
	map <string, int> scoreMap;
	bool checkInputError();
	void insert();
	void search();
public:
	GradeManager(string name);
	void run();
};

GradeManager::GradeManager(string program) { this->program = program; }

void GradeManager::insert() {
	string name;
	int score;
	while (true) {
		cout << "이름과 점수>> ";
		cin >> name >> score;

		if (checkInputError()) continue;

		if (scoreMap.find(name) != scoreMap.end()) {
			cout << name << "의 점수를 수정할 수 없음" << endl;
			break;
		}
		scoreMap.insert(make_pair(name, score));
		break; 
	}
}

void GradeManager::search() {
	string name;
	cout << "이름>> ";
	cin >> name;
	if (scoreMap.find(name) == scoreMap.end()) cout << name << "은 없는 사람임" << endl;
	else {
		int score = scoreMap[name];
		cout << name << "의 점수는 " << score << endl;
	}
}

bool GradeManager::checkInputError() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "입력 오류" << endl;
		return true;
	}
	else return false;
}
void GradeManager::run() {
	int menu;
	cout << "***** 점수관리 프로그램 " << program << "을 시작합니다 *****" << endl;
	while (true) {
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> menu;
		if (checkInputError()) continue;
		switch (menu) {
		case 1: insert(); break;
		case 2: search(); break;
		case 3: cout << "프로그램을 종료합니다..."; return;
		}
	}
}

int main() {
	GradeManager gm("HIGH SCORE");
	gm.run();
}