//#include <iostream>
//using namespace std;
//
//int dp[1000001] = { 0, };
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int testcase, n, index = 3;
//	cin >> testcase;
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 4;
//	while (testcase--) {
//		cin >> n;
//		if (n <= index)
//			cout << dp[n] << "\n";
//		else {
//			for (int i = index + 1; i <= n; i++) {
//				dp[i] = ((dp[i - 3] + dp[i - 2]) % 1000000009 + dp[i - 1]) % 1000000009;
//			}
//			index = n;
//			cout << dp[n] << "\n";
//		}
//	}
//
//	return 0;
//}