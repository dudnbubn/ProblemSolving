//// 2 x n tiling ���� ���ߴ� ��쿡�� 2x1 Ÿ�� 2���� 2x2 Ÿ�Ϸ� �ٲ�� ��츦 �߰��� ���Ѵ�.
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
//		int cnt = 0;
//		for (int j = 1; j <= i; j++) {
//			cnt += nCr(i, j);
//		}
//		tile[n] = (tile[n] + (1 + cnt) * nCr(n - i, i)) % 10007;
//		
//	}
//
//	return tile[n];
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << tiling(n);
//	return 0;
//}