#include <iostream>

using namespace std;

int dp[5001];

bool check(int number) {
	int bits = 0;

	int digit;
	while (number) {
		digit = number % 10;
		number /= 10;

		if ((bits & (1 << digit)))	return false;
		bits |= (1 << digit);
	}
	return true;
}

int main() {
	for (int i = 1; i <= 5000; i++) {
		dp[i] = dp[i - 1];
		if (check(i)) dp[i]++;
	}
	
	int N, M;
	while (true) {
		cin >> N >> M;
		if (cin.eof())	break;
		cout << dp[M] - dp[N - 1] << "\n";
	}
}