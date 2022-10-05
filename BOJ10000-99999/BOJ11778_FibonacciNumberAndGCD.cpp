#include <iostream>
#include <unordered_map>

using namespace std;

long long euclid(long long a, long long b) {
	long long temp = a > b ? a : b;
	b = a < b ? a : b;
	a = temp;
	long long n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

#define MOD 1000000007
unordered_map<long long, int> um;

long long fibo(long long n) {
	if (n == 0)	return 0;
	if (n <= 2)	return 1;
	if (um.find(n) != um.end())	return um[n];

	long long k;
	if (n & 1) {
		k = (n + 1) / 2;
		return um[n] = (fibo(k) * fibo(k) % MOD + fibo(k - 1) * fibo(k - 1) % MOD) % MOD;
	}
	else {
		k = n / 2;
		return um[n] = ((2 * fibo(k - 1) % MOD + fibo(k)) % MOD * fibo(k)) % MOD;
	}
}

int main() {
	long long n = 0, m = 0;
	cin >> n >> m;
	long long gcd = euclid(n, m);

	cout << fibo(gcd);

	return 0;
}