//// 왼쪽부터 어떤 i행 j열까지의 스티커의 최댓값은 해당 위치의 반대 행(i=0 일 때 1, 1일때 0)의 j-1 열과 j-2 열 중 큰 값과 자신을 더한 값이 된다.
//// 마지막 열 까지 모두 구한 후 마지막 열의 0행과 1행 중 큰 값이 스티커 점수의 최댓값이 된다.
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int dp[2][100001]{ 0, };
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int testcase, n;
//	cin >> testcase;
//	while (testcase--) {
//		cin >> n;
//		for (int i = 0; i < n; i++)	cin >> dp[0][i];
//		for (int i = 0; i < n; i++)	cin >> dp[1][i];
//		
//		dp[0][1] += dp[1][0];
//		dp[1][1] += dp[0][0];
//		for (int i = 2; i < n; i++) {
//			dp[0][i] += max(dp[1][i - 2], dp[1][i - 1]);
//			dp[1][i] += max(dp[0][i - 2], dp[0][i - 1]);
//		}
//		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
//	}
//
//	return 0;
//}