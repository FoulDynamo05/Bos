#include <iostream>
using namespace std;

int findCollatzChain(unsigned long a) {
	int count = 1;
	while (a > 1) {
		if (a % 2 != 0) {
			a = a * 3 + 1;
		}
		else {
			a /= 2;
		}
		count++;
	}

	return count;
}

int main(void) {
	//1 milyonun altýndaki baþlangýç deðerleri arasýndan en uzun iþlem yaptýran collatz sekansýný buluyo
	int max = 0, chain = 0, i = 1, largest = 0;
	while (i < 1000000) {
		chain = findCollatzChain(i);
		if (chain > max) {
			max = chain;
			largest = i;
		}
		i++;
		printf("i: %d, max: %d, largest: %d, chain: %d \n", i, max, largest, chain);
	}

}