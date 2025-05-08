#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "아래에 한 줄을 입력하세요 (exit를 입력하면 종료합니다)\n>>";

    while (true) {
        string input;
        getline(cin, input);

        if (input == "exit") break;

        string reversed = input;
        reverse(reversed.begin(), reversed.end());

        cout << reversed << "\n>>";
    }
    return 0;
}