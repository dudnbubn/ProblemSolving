#include <iostream>

using namespace std;

#define MOD 1'000'000'007

long long get_gcd(long long a, long long b) {
	long long n = a > b ? a : b;
	b = a < b ? a : b;
	a = n;
	n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

long long get_lcm(long long a, long long b) {
	long long gcd = get_gcd(a, b);
	return (a * b) / gcd;
}

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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	long long denominator, numerator;
	cin >> denominator >> numerator;

	long long next_denom, next_numer;
	long long gcd, lcm;
	for (int i = 0; i < N - 1; i++) {
		cin >> next_denom >> next_numer;
		lcm = get_lcm(denominator, next_denom);
		numerator = (numerator * (lcm / denominator) + next_numer * (lcm / next_denom)) % MOD;
		denominator = lcm % MOD;
	}
	
	gcd = get_gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	if (denominator == 1) 
		cout << numerator;
	else 
		cout << (numerator * power(denominator, MOD - 2)) % MOD;

	return 0;
}