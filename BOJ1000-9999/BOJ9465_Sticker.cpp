//// ���ʺ��� � i�� j�������� ��ƼĿ�� �ִ��� �ش� ��ġ�� �ݴ� ��(i=0 �� �� 1, 1�϶� 0)�� j-1 ���� j-2 �� �� ū ���� �ڽ��� ���� ���� �ȴ�.
//// ������ �� ���� ��� ���� �� ������ ���� 0��� 1�� �� ū ���� ��ƼĿ ������ �ִ��� �ȴ�.
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