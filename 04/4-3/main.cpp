#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int count = 0;

    cout << "���ڿ� �Է�>> ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 'a') count++;
    }
    cout << "���� a�� " << count << "�� �ֽ��ϴ�." << endl;

    cout << "'a' ���ڰ� ��ġ�� �ε���: ";
    size_t index = text.find('a');
    bool first = true;

    while (index != string::npos) {
        if (!first) cout << ", ";
        cout << index - 8;
        first = false;
        index = text.find('a', index + 1);
    }
    cout << endl;
    return 0;
}