#include <iostream>
#include <unordered_map>

using namespace std;

#define MOD 1000000007

unordered_map<long long, long long> um;

long long Fibo(long long N) {
	if (N == 0)	return 0;
	if (N <= 2)	return 1;
	if (um.find(N) != um.end())	return um[N];

	long long k;
	if (N & 1) {
		k = (N + 1) / 2;
		return um[N] = (Fibo(k) * Fibo(k) + Fibo(k - 1) * Fibo(k - 1)) % MOD;
	}
	else {
		k = N / 2;
		return um[N] = (2 * Fibo(k - 1) + Fibo(k)) * Fibo(k) % MOD;
	}
}

int main() {
	long long N;
	cin >> N;

	cout << Fibo(N) * Fibo(N + 1) % MOD;
	return 0;
}