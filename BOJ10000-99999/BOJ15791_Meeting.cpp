#include <iostream>

using namespace std;

#define MOD 1'000'000'007

long long power(long long base, long long expo) {
	long long result = 1;
	while (expo) {
		if (expo & 1)	result = (result * base) % MOD;
		base = (base * base) % MOD;
		expo >>= 1;
	}
	return result;
}

int main() {
	int N, M;
	cin >> N >> M;

	M = M < N - M ? M : N - M;
	long long fact_n = 1, fact_m = 1, fact_dif = 1;
	for (int i = 2; i <= N; i++) {
		if (i <= N)	fact_n = (fact_n * i) % MOD;
		if (i <= M)	fact_m = (fact_m * i) % MOD;
		if (i <= N-M)	fact_dif = (fact_dif * i) % MOD;
	}

	long long fact_m_inv = power(fact_m, MOD - 2);
	long long fact_dif_inv = power(fact_dif, MOD - 2);

	cout << (fact_n * fact_m_inv) % MOD * fact_dif_inv % MOD;
}