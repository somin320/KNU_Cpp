#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand((unsigned int)time(0));
    cout << "�Ʒ��� �� ���� �Է��ϼ��� (exit�� �Է��ϸ� �����մϴ�)\n>>";

    while (true) {
        string input;
        getline(cin, input);

        if (input == "exit") break;
        if (input.empty()) continue;

        int indexToReplace = rand() % input.length();

        char randomLetter;
        do {
            randomLetter = 'a' + (rand() % 26);
        } while (randomLetter == input[indexToReplace]);

        input[indexToReplace] = randomLetter;

        cout << input << "\n>>";
    }
    return 0;
}