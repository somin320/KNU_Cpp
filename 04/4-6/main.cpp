#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "�Ʒ��� �� ���� �Է��ϼ��� (exit�� �Է��ϸ� �����մϴ�)\n>>";

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