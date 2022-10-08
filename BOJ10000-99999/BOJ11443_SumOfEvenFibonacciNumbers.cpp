#include <iostream>
#include <unordered_map>

using namespace std;

#define MOD 1000000007

unordered_map<long long, long long> um;

long long Fibo(long long N) {
	if (N == 0)	return 0;
	if (N <= 2)	return 1;
	if (um.find(N) != um.end())	return um[N];

	long long k = N & 1 ? (N + 1) / 2 : N / 2;
	return um[N] = N & 1 ? (Fibo(k) * Fibo(k) + Fibo(k - 1) * Fibo(k - 1)) % MOD : (2 * Fibo(k - 1) + Fibo(k)) * Fibo(k) % MOD;
}

int main() {
	long long N;
	cin >> N;

	if (N % 2 == 0)	N++;
	cout << Fibo(N) - 1;
	return 0;
}