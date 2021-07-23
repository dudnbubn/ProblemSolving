//#include <iostream>
//using namespace std;
//
//int dp[201][201] = { 0, };
//
//int Cases(int n, int k) {
//	if (k == 1)
//		return 1;
//	if (dp[n][k] != 0)
//		return dp[n][k];
//	int cnt = 0;
//	for (int i = 0; i < n; i++)
//		cnt = (cnt + Cases(n - i, k - 1)) % 1000000000;
//	cnt++;
//	return dp[n][k] = cnt;
//}
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	cout << Cases(n, k);
//
//	return 0;
//}