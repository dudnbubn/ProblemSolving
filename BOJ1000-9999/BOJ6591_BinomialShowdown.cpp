#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<pair<int, int>, int> m;

int nCr(int n, int k) {
	if (m.find({ n, k }) != m.end())	return m[{n, k}];
	if (n < k)	return 0;
	if (k == 0 || k == n)	return 1;
	if (k == 1 || k == n - 1)	return n;
	m.insert({ { n, k }, nCr(n - 1, k) + nCr(n - 1, k - 1) });
	return m[{n, k}];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	while (n != 0 || k != 0) {
		cout << nCr(n, k) << "\n";
		cin >> n >> k;
	}
	return 0;
}