#include <iostream>

int main() {
	int a, b = 1, c = 0, sum = 0;
	do {
		a = b + c;
		c = b;
		b = a;

		if (a % 2 == 0) {
			sum += a;
		}

	} while (a < 4000000);
	
	std::cout << sum;

	return 0;
}
