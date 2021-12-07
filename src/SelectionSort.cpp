#include <iostream>
using namespace std;

int main(void) {
	int arr[] = { 42, 13, 25, 63, 11, 86, 123, 3 };
	int min = 0, temp = 0, minLoc = 0, arrLen = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arrLen; i++) {
		min = arr[i];
		for (int j = i; j < arrLen; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minLoc = j;
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[minLoc] = temp;
	}

	for (int i = 0; i < arrLen; i++) {
		cout << arr[i] << endl;
	}


	return 0;
}