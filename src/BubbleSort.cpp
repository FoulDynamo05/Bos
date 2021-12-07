#include <iostream>
using namespace std;

int main(void) {
	int arr[] = { 6, 3, 8, 5, 2, 7, 4, 1 };
	int arrLen = sizeof(arr) / sizeof(arr[0]), temp = 0, j = arrLen;
	bool swapped = true;

	while (swapped) {
		swapped = false;
		for (int i = 1; i < j; i++) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}
		j--;
	}

	for (int i = 0; i < arrLen; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}