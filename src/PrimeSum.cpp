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
	long long sum = 0;

	for (int i = 2; i < 2000000; i++) {
		if (isPrime(i)) {
			sum += i;
		}
	}

	cout << sum;

	//ilk deneme
	/*for (int i = 2; i < 2000000; i++) {
		for (int j = 2; j <= i; j++) {
			if (i == j) {
				cout << i << endl;
				sum += i;
			}
			if (i % j == 0) {
				break;
			}
		}
	}*/

}