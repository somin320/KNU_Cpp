#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> v;
	int input;
	while (true) {
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
		cin >> input;
		if (input == 0) break;

		v.push_back(input);
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << endl;

		int sum = 0;
		for (int i = 0; i < v.size(); i++) sum += v[i];
		double average = static_cast<double>(sum) / v.size();
		cout << "��� = " << average << endl;
	}
}