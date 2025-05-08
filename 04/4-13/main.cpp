#include <iostream>
#include <string>
using namespace std;

class Histogram {
    string str;
    int alphabet[26];
public:
    Histogram(string s) {
        for (char& ch : s) {
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
        }
        str = s;
    }
    void put(string new_str) {
        for (char& ch : new_str) {
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
        }
        str.append(new_str);
    }
    void putc(char c) {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        str.push_back(c);
    }
    void print();
private:
    int getAlphabetSize();
    void countAlphabet();
};

int Histogram::getAlphabetSize() {
    int cnt = 0;
    for (char c : str) {
        if (c >= 'a' && c <= 'z')
            cnt++;
    }
    return cnt;
}

void Histogram::countAlphabet() {
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 0;
    }
    for (char c : str) {
        if (c >= 'a' && c <= 'z')
            alphabet[c - 'a']++;
    }
}

void Histogram::print() {
    cout << str << endl << endl;
    cout << "ÃÑ ¾ËÆÄºª ¼ö " << getAlphabetSize() << endl << endl;
    countAlphabet();
    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        cout << ch << " (" << alphabet[i] << ")\t: ";
        for (int j = 0; j < alphabet[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n");
    elvisHisto.put("falling in love with you");
    elvisHisto.putc('-');
    elvisHisto.put("Elvis Presley");
    elvisHisto.print();
    return 0;
}