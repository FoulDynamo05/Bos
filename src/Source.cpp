#include <iostream>
using namespace std;

int fact(int n);
void printArr(int arr[], int size);
int permutate(int arr[], int size);
void changeLeast(int arr[], int size, int key);

int main(void)
{
	//5 Elemanlý bir kümenin permutasyonu (Elemanlarý birbirinden farklý)
	int arr[5] = { 0,1,2,3,4 }, size = sizeof(arr) / sizeof(arr[0]);
	permutate(arr, size);

	return 0;
}

int permutate(int arr[], int size)
{
	int temp = 0;
	int last = size - 1;
	int steps = fact(last);
	for (int i = 0; i < size; i++)
	{	
		printf("Before:");
		printArr(arr, size);

		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				printArr(arr, size);
				temp = arr[last];
				arr[last] = arr[last - 1];
				arr[last - 1] = temp;
				printArr(arr, size);

				if (j != 2)
				{
					temp = arr[last - 2];
					arr[last - 2] = arr[last - 1];
					arr[last - 1] = temp;
				}
			
			}

			if (k >= 2)
			{
				temp = arr[last];
				arr[last] = arr[1];
				arr[1] = temp;
			}
			else
			{
				temp = arr[last - 3];
				arr[last - 3] = arr[last - 2];
				arr[last - 2] = temp;
			}
			printf("\n");
		}
		changeLeast(arr, size, arr[0]);
	}
	
	return 0;
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	printf("\n");
}

int fact(int n)
{
	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}
	return num;
}

void changeLeast(int arr[], int size, int key)
{
	int temp = 0;
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > key)
		{
			temp = arr[i];
			num = i;
			break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < temp && arr[i] > key)
		{
			num = i;
		}
	}

	temp = arr[0];
	arr[0] = arr[num];
	arr[num] = temp;
	
}