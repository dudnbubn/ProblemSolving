#include <iostream>

using namespace std;

int main() {
	long long N;
	cin >> N;

	long long result = N;
	long long div = 2;
	while (div * div <= N) {
		if (N % div == 0) {
			result = result / div * (div - 1);
			while (N % div == 0)
				N /= div;
		}
		else
			div++;
	}

	if (N > 1)
		result = result / N * (N - 1);
	cout << result;

	return 0;
}