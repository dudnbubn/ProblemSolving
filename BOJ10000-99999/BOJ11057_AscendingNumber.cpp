//#include <iostream>
//using namespace std;
//
//int dp[10][1001] = { 0, };
//
//int AscendingNumber(int first, int length) {
//	if (dp[first][length] != 0)
//		return dp[first][length];
//	
//	for (int i = first; i < 10; i++)
//		dp[first][length] = (dp[first][length] + AscendingNumber(i, length - 1)) % 10007;
//	return dp[first][length];
//}
//
//int main() {
//	for (int i = 0; i < 10; i++)
//		dp[i][1] = 1;
//	int n;
//	cin >> n;
//	int answer = 0;
//	for (int i = 0; i < 10; i++) {
//		answer = (answer + AscendingNumber(i, n)) % 10007;
//	}
//	cout << answer;
//	return 0;
//}