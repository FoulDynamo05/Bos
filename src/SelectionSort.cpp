#include <iostream>
using namespace std;

int main(void) {
	int arr[] = { 6, 3, 9, 2, 7, 1, 4, 8, 5 };
	int min = 0, temp = 0, minLoc = 0, arrLen = sizeof(arr) / sizeof(arr[0]);

	printf("siralanmamis dizi: ");
	for (int i = 0; i < arrLen; i++) {
		printf("%d, ", arr[i]);
	}

	printf("\n\n");

	for (int i = 0; i < arrLen; i++) {
		printf("i: %d -> ", i);
		min = arr[i];
		minLoc = i;
		for (int j = i; j < arrLen; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minLoc = j;
			}
		}

		printf("%d ve %d degisti ", arr[i], min);
		temp = arr[i];
		arr[i] = min;
		arr[minLoc] = temp;
		for (int z = 0; z < arrLen; z++) {
			printf("%d, ", arr[z]);
		}
		printf("\n");

	}


	return 0;
}
