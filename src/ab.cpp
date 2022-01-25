#include <iostream>
using namespace std;

int power(int a, int b);
int pf(int num, int pow);
int d(int num);
bool isAb(int a);

//bool isAbSum(int k);
int countAb(int limit);

void printArr(int arr[], int size);
int summarize(int start, int end);

int main(void)
{
	int limit = 28123;
	int sum = summarize(1, limit);
	int size = countAb(limit);
	int* dizi = new int[size];

	bool foundFlag = false;

	dizi[0] = 5;

	for (int i = 12, j = 0; i < limit; i++)
	{
		if (isAb(i))
		{
			dizi[j] = i;
			j++;
		}

		if (j >= size)
			break;
	}

	//printArr(dizi, size);

	for (int i = 1; i <= limit; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (dizi[j] > i)
				break;

			for (int k = 0; k < size; k++)
			{
				if (dizi[j] + dizi[k] > i)
					break;

				if (dizi[j] + dizi[k] == i)
				{
					sum -= i;
					foundFlag = true;
					break;
				}
			}

			if (foundFlag)
				break;
		}

		foundFlag = false;
	}

	cout << sum;

	return 0;
}

int summarize(int start, int end)
{
	int sum = 0;
	for (int i = start; i <= end; i++)
	{
		sum += i;
	}
	return sum;
}

int countAb(int limit)
{
	int count = 0;
	for (int i = 12; i <= limit; i++)
	{
		if (isAb(i))
		{
			count++;
		}
	}

	return count;
}

bool isAb(int a)
{
	if (d(a) > a)
		return true;

	return false;
}

int d(int num)
{
	if (num == 1)
		return 1;

	short temp = num;
	short n = 2;
	short powerCount = 0;
	int sum = 1;

	while (num > 1)
	{
		powerCount = 0;
		while (num % n == 0)
		{
			num /= n;
			powerCount++;

			if (num % n != 0)
			{
				sum *= pf(n, powerCount);
			}
		}

		n++;
	}

	return sum - temp;

}

int pf(int num, int pow)
{
	int sum = 1;

	for (int i = 1; i <= pow; i++)
	{
		sum += power(num, i);
	}

	return sum;
}

int power(int a, int b)
{
	short temp = a;

	for (int i = 1; i < b; i++)
	{
		a *= temp;
	}

	return a;
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

/*bool isAbSum(int k)
{
	bool isAb = false;
	for (int i = 12; i < k; i++)
	{
		if (!isAb(i))
			continue;

		isAb = true;
		for (int j = 12; j <= i; j++)
		{
			if (isAb && isAb(j))
			{
				if (i + j == k)
					return false;
			}

			if (i + j > k)
				return true;
		}

		isAb = false;
	}

	return true;
}*/
