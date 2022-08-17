#include <iostream>

using namespace std;

long long square[1000002];
bool check[1000001];


int main() {
	long long minimum, maximum;
	cin >> minimum >> maximum;

	long long MAX_VALUE = 1e12 + 1e6;

	for (long long i = 1; i * i <= MAX_VALUE; i++) 
		square[i] = i * i;
	square[1000001] = MAX_VALUE + 1;

	long long start;
	for (int i = 2; square[i] <= maximum; i++) {
		long long start = (minimum - 1) / square[i] * square[i] + square[i];
		while (minimum <= start && start <= maximum) {
			check[start - minimum] = true;
			start += square[i];
		}
	}

	int result = 0;
	for (long long i = 0; i <= maximum - minimum; i++) 
		if (!check[i])	result++;

	cout << result;

	return 0;
}