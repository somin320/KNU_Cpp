#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player {
	int card[3];
	string name;
public:
	Player() :Player("�÷��̾�") {}
	Player(string name) { this->name = name; }
	string getName() { return name; }
	bool playGambling();
};
bool Player::playGambling() {
	for (int i = 0; i < 3; i++) {
		card[i] = rand() % 3;
		cout << "\t" << card[i];
	}
	for (int i = 0; i < 2; i++) {
		if (card[i] != card[i + 1]) {
			return false;
		}
	}
	return true;
}

class GamblingGame {
	Player player[2];
	bool isGameCompleted = false;
public:
	GamblingGame();
	void play();
};

GamblingGame::GamblingGame() {
	cout << "*****���� ������ �����մϴ�. *****" << endl;
	string name;
	cout << "ù��° ���� �̸�>>";
	cin >> name;
	player[0] = Player(name);
	cout << "�ι�° ���� �̸�>>";
	cin >> name;
	player[1] = Player(name);
	getchar();
}

void GamblingGame::play() {
	int i = 0;
	while (!isGameCompleted) {
		cout << player[i % 2].getName() << ":<Enter>";
		getchar();
		if (player[i % 2].playGambling()) {
			isGameCompleted = true;
			cout << "\t" << player[i % 2].getName() << "�� �¸�!!" << endl;
		}
		else {
			cout << "\t�ƽ�����!" << endl;
		}
		i++;
	}
}

int main() {
	GamblingGame game;
	game.play();

	return 0;
}