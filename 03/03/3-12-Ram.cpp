#include <iostream>
#include "3-12-Ram.h"
using namespace std;

Ram::Ram(){
	for (int x = 0; x < 100; x++){
		for (int y = 0; y < 1024; y++){
			mem[x * y] = 0;
		}
	}
	size = 100 * 1024;
}

Ram :: ~Ram() {
	cout << endl << "�޸� ���ŵ�" << endl;
}

void Ram::write(int address, char value) {
	mem[address] = value;
}

char Ram::read(int address) {
	return mem[address];
}