#include <iostream>

using namespace std;

bool isPrime[8000000];

void Eratos() {
	for (int i = 2; i < 8000000; i++)
		isPrime[i] = true;

	for (int i = 2; i * i < 8000000; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < 8000000; j += i)
				isPrime[j] = false;
		}
	}
}

int main() {
	Eratos();

	int k;
	cin >> k;

	int index = 1;
	while (k) {
		index++;
		if (isPrime[index])	k--;
	}
	cout << index;
	return 0;
}