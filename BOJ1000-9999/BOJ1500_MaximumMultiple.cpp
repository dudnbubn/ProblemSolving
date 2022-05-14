//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//long long dp[21][101];
//
//int main() {
//	int s, k;
//	cin >> s >> k;
//	for (int i = 1; i <= s; i++)	dp[1][i] = i;
//
//	for (int i = 2; i <= k; i++) {
//		for (int j = i; j <= s; j++) {
//			for (int k = 1; k < j; k++) {
//				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] * k);
//			}
//		}
//	}
//	cout << dp[k][s];
//	return 0;
//}