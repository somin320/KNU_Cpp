#include <iostream>
using namespace std;

class Matrix {
	int mat[4] = { 0 };
public:
	Matrix() {}
	Matrix(int a, int b, int c, int d) {
		mat[0] = a;
		mat[1] = b;
		mat[2] = c;
		mat[3] = d;
	}
	void show() { cout << "Matrix = { " << mat[0] << " " << mat[1] << " " << mat[2] << " " << mat[3] << " }" << endl; }
	friend int* operator >> (Matrix& A, int* B);
	friend Matrix& operator << (Matrix& A, int* B);
};
int* operator >> (Matrix& A, int* B) {
	B[0] = A.mat[0];
	B[1] = A.mat[1];
	B[2] = A.mat[2];
	B[3] = A.mat[3];

	return B;
}
Matrix& operator << (Matrix& A, int* B) {
	A.mat[0] = B[0];
	A.mat[1] = B[1];
	A.mat[2] = B[2];
	A.mat[3] = B[3];
	return A;
}

int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}