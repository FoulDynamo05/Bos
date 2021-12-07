#include <iostream>
using namespace std;

int sqr(int a) {
	return a * a;
}

bool isTriplet(int a, int b, int c) {
	if (a < c && b < c && sqr(a) + sqr(b) == sqr(c)) {
		return true;
	}
	return false;
}

int main(void) {
	// a + b + c = 1000 olan pisagor uclusunun carpimini bulan program
	bool solved = false;
	int m = 2, mTemp = m, n = 1, a = 0, b = 0, c = 0;
	while (!solved) {
		while (true) {
			a = sqr(m) - sqr(n);
			b = 2 * m * n;
			c = sqr(m) + sqr(n);

			if (a + b + c > 1000) {
				break;
			}

			if (a + b + c == 1000 && isTriplet(a, b, c)) {
				printf("Bu degerlerde geldi a: %d, b: %d, c: %d, m: %d, mTemp: %d, n: %d carpim sonucu: ", a, b, c, m, mTemp, n);
				solved = true;
				cout << a * b * c;
				break;
			}
			m++;
			n++;
		}
		m = ++mTemp;
		n = 1;
	}

}