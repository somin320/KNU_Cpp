#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int count = 0;

    cout << "문자열 입력>> ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 'a') count++;
    }
    cout << "문자 a는 " << count << "개 있습니다." << endl;

    cout << "'a' 문자가 위치한 인덱스: ";
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