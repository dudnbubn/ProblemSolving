#include <iostream>
#include <algorithm>

using namespace std;

long long cnt[70];

long long recur(long long start, long long end) {
	if (end == 0)	return 0;
	if (end == 1)	return 1;
	if (start == 0)	start = 1;
	long long div = 2;
	int c = 2;
	while (div <= start) {
		div *= 2;
		c++;
	}
	long long pdiv = div / 2;
	long long result = 0;
	if (div > end) 
		result = (end - start + 1) + recur(start % pdiv, end % pdiv);
	else {
		result = (div - start) + recur(start % pdiv, (div - 1) % pdiv);

		while (div * 2 - 1 <= end) {
			result += cnt[c];
			div *= 2;
			c++;
		}

		if (end >= div) 
			result += (end - div + 1) + recur(1, end % div);
			
	}
	return result;
}

int main() {
	cnt[1] = 1;
	long long exp = 1;
	int i = 2;
	while (exp <= (long long)1e16 - 1) {
		cnt[i] = (i + 1) * exp;
		exp *= 2;
		i++;
	}

	long long A, B;
	cin >> A >> B;
	cout << recur(A, B);

	return 0;
}