// gcd 와 lcm 이 같은 경우도 생각해보자.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Euclid(long long a, long long b) {
	long long n = min(a, b);
	a = max(a, b);
	b = n;
	n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int main() {
	long long gcd, lcm;
	cin >> gcd >> lcm;

	if (gcd == lcm) {
		cout << gcd << " " << gcd;
	}
	else {
		vector<int> v;
		for (long long i = gcd; i <= lcm / 2; i++)
			if (lcm % i == 0 && i % gcd == 0)
				v.push_back(i);

		long long temp;
		long long a, b, sum = 100000000;
		for (int i = 0; i < v.size(); i++) {
			temp = gcd * lcm / v[i];
			if (lcm % temp == 0 && Euclid(v[i], temp) == gcd) {
				if (sum > v[i] + temp) {
					sum = v[i] + temp;
					a = v[i];
					b = temp;
				}
			}
		}
		cout << a << " " << b;
	}
	
	return 0;
}