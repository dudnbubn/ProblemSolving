#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long power(long long base, int expo) {
	long long result = 1;
	while (expo) {
		if (expo & 1)	result = (result * base) % MOD;
		base = (base * base) % MOD;
		expo >>= 1;
	}
	return result;
}

int main() {
	int N, K;
	cin >> N >> K;
	K = K < N - K ? K : N - K;

	long long fact_n = 1, fact_k = 1, fact_dif = 1;
	for (int i = 2; i <= N; i++) {
		if (i <= N)	fact_n = (fact_n * i) % MOD;
		if (i <= K)	fact_k = (fact_k * i) % MOD;
		if (i <= N - K) fact_dif = (fact_dif * i) % MOD;
	}

	long long fact_k_inv = power(fact_k, MOD - 2);
	long long fact_dif_inv = power(fact_dif, MOD - 2);

	long long result = ((fact_n * fact_k_inv) % MOD * fact_dif_inv) % MOD;
	cout << result;

	return 0;
}