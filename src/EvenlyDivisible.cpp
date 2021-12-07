#include <iostream>
using namespace std;

bool isDivisible(int a, int b) {
	for (int i = 1; i <= b; i++) {
		if (a % i != 0) {
			return false;
		}
	}
	return true;
}


int main(void) {
	int number = 10;

	while (true) {
		if (isDivisible(number, 20)) {
			break;
		}
		number += 10;
	}

	cout << number;
}
