#include <iostream>
using namespace std;

int main(void) {
	int count = 0;
	int x = 1;
	int prime = 0;

	while (count < 10001) {
		for (int i = 2; i <= x; i++) {
			if (x == i) {
				count++;
				if (count == 10001) {
					prime = x;
				}
			}
			if (x % i == 0) {
				break;
			}
		}
		x++;
	}

	cout << prime;


}