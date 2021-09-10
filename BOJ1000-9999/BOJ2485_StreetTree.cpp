#include <iostream>
#include <algorithm>
using namespace std;

int n;
int trees[100000] = { 0, };

int euclid(int a, int b) {
	int n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> trees[i];
	sort(trees, trees + n);
	for (int i = n - 1; i > 0; i--)	trees[i] -= trees[i - 1];
	int gcd = trees[1];
	for (int i = 2; i < n; i++)	gcd = euclid(gcd, trees[i]);
	int tot = 0;
	for (int i = 1; i < n; i++)	tot += ((trees[i] / gcd) - 1);
	cout << tot;
	return 0;
}