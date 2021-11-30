#include <iostream>
using namespace std;

int main() 
{
	long long a = 600851475143;
	int max = 0;
	int i = 2;

	while (true) {
		if (a % i == 0) {
			while (true) {
				a /= i;

				if (a % i != 0) {
					max = i;
					break;
				}
			}
		}

		if (a == 1) {
			break;
		}

		i++;

	}
	
	cout << max;

	return 0;
}