#include <iostream>
using namespace std;

template <class T>
T biggest(T* arr, int size) {
	T max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	cout << biggest(x, 5) << endl;  // 5�� �迭 x�� ũ��. 100�� ��µȴ�.
}