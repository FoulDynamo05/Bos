#include <iostream>
using namespace std;

//10000 den kucuk amicable sayilarin toplami

int d(int num);
bool isA(int a);
int power(short a, short b);
int primeFact(short number, short power);

int main(void)
{
	int sum = 0;

	for (int i = 1; i < 10000; i++)
	{
		if (isA(i))
		{
			sum += i;
		}
	}

	cout << sum;
	return 0;
}

bool isA(int a)
{
	int b = d(a);
	int c = d(b);

	if (c == a && a != b)
		return true;

	return false;
}

//girilen sayinin kendisi haric pozitif tam bolenlerinin toplamini veren fonksiyon
int d(int num)
{
	if (num == 1)
		return 1;

	int prod = 1;
	int temp = num;
	short powerCount = 0;
	short n = 2;

	while (num > 1)
	{
		powerCount = 0;
		while (num % n == 0)
		{
			num /= n;
			powerCount++;
			if (num % n != 0)
			{
				prod *= primeFact(n, powerCount);
			}
		}

		n++;
	}

	return prod - temp;
}

int primeFact(short number, short pow)
{
	int sum = 1;

	for (int i = 1; i <= pow; i++)
	{
		sum += power(number, i);
	}

	return sum;
}

int power(short a, short b)
{
	short temp = a;
	for (int i = 1; i < b; i++)
	{
		a *= temp;
	}

	return a;
}
