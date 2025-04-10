#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand((unsigned int)time(0));
    cout << "아래에 한 줄을 입력하세요 (exit를 입력하면 종료합니다)\n>>";

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