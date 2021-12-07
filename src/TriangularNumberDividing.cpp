#include <iostream>
using namespace std;

int triangleSum(int a) {
	int sum = 0;
	for (int i = 1; i <= a; i++) {
		sum += i;
	}

	return sum;
}

int findDivisors(int a) {
	int divisor = 2;
	int positiveDivisors = 1;
	int count = 0;

	while (a > 1) {
		if (a % divisor == 0) {
			while (true) {
				a /= divisor;
				count++;
				if (a % divisor != 0) {
					break;
				}
			}
		}
		positiveDivisors *= count + 1;
		divisor++;
		count = 0;
	}

	return positiveDivisors;
}

int main(void) {
	int index = 1;
	while (true) {
		if (findDivisors(triangleSum(index)) > 500) {
			cout << triangleSum(index);
			break;
		}
		index++;
	}

	//ilk deneme başarısız ve çok yavaş
	/*int divCount = 0;
	int index = 1;

	while (true) {
		for (int j = 1, num = triangleSum(index); j <= num; j++) {
			if (num % j == 0) {
				divCount++;
			}
		}
		if (divCount > 500) break;
		if (divCount > 100) {
			cout << endl;
			cout << divCount << endl;
			cout << index << endl;
			cout << endl;
		}
		divCount = 0;
		index++;
	}*/

}
