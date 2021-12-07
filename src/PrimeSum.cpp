#include <iostream>
using namespace std;

bool isPrime(int a) {
	int sqrNum = (int)sqrt(a);
	for (int i = 2; i <= sqrNum; i++) {
		if (a % i == 0) {
			return false;
		}
	}

	return true;
}

int main(void) {
	//Sum of primes from 1 to 2000000
	long long sum = 0;

	for (int i = 2; i < 2000000; i++) {
		if (isPrime(i)) {
			cout << i << endl;
			sum += i;
		}
	}

	cout << sum;

	for (int i = 125125; i < 2000000; i++) {
		for (int j = 2; j <= 1251252; j++) {
			if (i == j) {
				cout << i << endl;
				sum += i;
			}
			if (i % j == 0) {
				break;
			}
		}
	}

}