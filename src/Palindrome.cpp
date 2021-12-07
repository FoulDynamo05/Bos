#include <iostream>
using namespace std;

int isPalindrome(int a) {
	int temp = a;
	int rev = 0;

	while (temp > 0) {
		rev = (rev * 10) + (temp % 10);
		temp /= 10;
	}

	return rev == a;
}

int main(void) {

	int i = 999, j = 999, x = 0;
	while (true) {
		if (isPalindrome(i * j)) {
			break;
		}

		if (x % 16 == 0) {
			i--;
		}
		else {
			j--;
		}
		x++;
	}

	cout << i * j;

	return 0;
}