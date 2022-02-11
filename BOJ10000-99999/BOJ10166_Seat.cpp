#include <iostream>
#include <algorithm>

using namespace std;

bool arr[2001][2001];

int euclid(int a, int b) {
	int temp = max(a, b);
	b = min(a, b);
	a = temp;
	int n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int main() {
	int d1, d2;
	cin >> d1 >> d2;
	
	int gcd;
	int result = 0;
	for (int i = d1; i <= d2; i++) {
		for (int j = 1; j < i; j++) {
			gcd = euclid(i, j);
			if (!arr[j / gcd][i / gcd]) {
				result++;
				arr[j / gcd][i / gcd] = true;
			}
		}
	}
	cout << result + 1;
	return 0;
}