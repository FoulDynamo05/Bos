#include <iostream>
using namespace std;

int getAlphabetic(int digit);
int getLen(int n);
int vocalize(int n);
int power(int a, int n);

int main(void)
{
	int sum = 0;
	for (int i = 1; i <= 1000; i++)
	{
		sum += vocalize(i);
	}
	cout << sum;
	return 0;
}

int getLen(int n)
{
	int count = 0;
	do
	{
		count++;
		n /= 10;

	} while (n > 0);

	return count;
}

int vocalize(int n)
{
	int length = getLen(n);
	int digit = 0, pow = 0, sum = 0;
	bool flag = false;
	if (n % 100 > 10 && n % 100 < 20) flag = true;
	if (n % 100 == 0 && n < 1000) sum = -3;

	for (int i = 0; i < length; i++)
	{
		if (flag)
		{
			sum += getAlphabetic(n % 100);
			n /= 100;
			flag = false;
			i = 1;
			continue;
		}

		pow = power(10, i);
		digit = (n % 10) * pow;
		if (digit > 99 && digit != 0)
		{
			sum += getAlphabetic(digit / pow);
			sum += getAlphabetic(pow);
		}
		else
		{
			sum += getAlphabetic(digit);
		}
		n /= 10;
	}

	cout << sum << endl;
	return sum;
}

int power(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}

	if (n == 1)
	{
		return a;
	}

	int power = a;
	for (int i = 1; i < n; i++)
	{
		power *= a;
	}
	return power;
}

int getAlphabetic(int digit)
{
	if (digit == 0) return 0;
	if (digit == 1)
	{
		cout << "one ";
		return 3;
	}
	else if (digit == 2)
	{
		cout << "two ";
		return 3;
	}
	else if (digit == 3)
	{
		cout << "three ";
		return 5;
	}
	else if (digit == 4)
	{
		cout << "four ";
		return 4;
	}
	else if (digit == 5)
	{
		cout << "five ";
		return 4;
	}
	else if (digit == 6)
	{
		cout << "six ";
		return 3;
	}
	else if (digit == 7)
	{
		cout << "seven ";
		return 5;
	}
	else if (digit == 8)
	{
		cout << "eight ";
		return 5;
	}
	else if (digit == 9)
	{
		cout << "nine ";
		return 4;
	}
	else if (digit == 10)
	{
		cout << "ten ";
		return 3;
	}
	else if (digit == 11)
	{
		cout << "eleven ";
		return 6;
	}
	else if (digit == 12)
	{
		cout << "twelve ";
		return 6;
	}
	else if (digit == 13)
	{
		cout << "thirteen ";
		return 8;
	}
	else if (digit == 14)
	{
		cout << "fourteen ";
		return 8;
	}
	else if (digit == 15)
	{
		cout << "fifteen ";
		return 7;
	}
	else if (digit == 16)
	{
		cout << "sixteen ";
		return 7;
	}
	else if (digit == 17)
	{
		cout << "seventeen ";
		return 9;
	}
	else if (digit == 18)
	{
		cout << "eighteen ";
		return 8;
	}
	else if (digit == 19)
	{
		cout << "nineteen ";
		return 8;
	}
	else if (digit == 20)
	{
		cout << "twenty ";
		return 6;
	}
	else if (digit == 30)
	{
		cout << "thirty ";
		return 6;
	}
	else if (digit == 40)
	{
		cout << "forty ";
		return 5;
	}
	else if (digit == 50)
	{
		cout << "fifty ";
		return 5;
	}
	else if (digit == 60)
	{
		cout << "sixty ";
		return 5;
	}
	else if (digit == 70)
	{
		cout << "seventy ";
		return 7;
	}
	else if (digit == 80)
	{
		cout << "eighty ";
		return 6;
	}
	else if (digit == 90)
	{
		cout << "ninety ";
		return 6;
	}
	else if (digit == 100)
	{
		cout << "hundred and ";
		return 10;
	}
	else if (digit == 1000)
	{
		cout << "thousand ";
		return 8;
	}
}