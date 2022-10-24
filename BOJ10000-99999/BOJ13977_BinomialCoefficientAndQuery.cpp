#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

long long fact[4000001];
vector<pair<int, int>> queries;

long long power(long long base, long long expo) {
	long long result = 1;
	while (expo) {
		if (expo & 1)	result = (result * base) % MOD;
		base = (base * base) % MOD;
		expo >>= 1;
	}
	return result;
}

long long nCr(long long N, long long R) {
	long long fact_R_inv, fact_dif_inv;

	fact_R_inv = power(fact[R], MOD - 2);
	fact_dif_inv = power(fact[N - R], MOD - 2);
	return ((fact[N] * fact_R_inv) % MOD * fact_dif_inv) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> M;

	int N, K;
	int maximum = 0;
	for (int i = 0; i < M; i++) {
		cin >> N >> K;
		queries.push_back({ N, K });
		maximum = maximum > N ? maximum : N;
	}
	
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= maximum; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	for (pair<int, int> query : queries) {
		N = query.first;
		K = query.second;

		cout << nCr(N, K) << "\n";
	}
	return 0;
}