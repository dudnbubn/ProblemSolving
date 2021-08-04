//#include <iostream>
//using namespace std;
//
//long long ncr[1001][1001] = { 0, };
//long long tile[1001] = { 0, };
//
//long long nCr(int n, int r) {
//	if (r == 0)
//		return 1;
//	if (n < r)
//		return 0;
//	if (ncr[n][r] != 0)
//		return ncr[n][r];
//	return ncr[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % 10007;
//}
//long long tiling(int n) {
//	if (tile[n] != 0)
//		return tile[n];
//	tile[n] = 1;
//	for (int i = 1; i <= n / 2; i++) {
//		tile[n] = (tile[n] + nCr(n - i, i)) % 10007;
//	}
//	return tile[n];
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << tiling(n);
//	return 0;
//}