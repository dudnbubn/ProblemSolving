//#include <iostream>
//
//using namespace std;
//
//#define INF 987654321
//
//int N;
//int RGB[3];
//int dp[1001][3][3];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> N;
//	for (int j = 0; j < 3; j++)
//		for (int k = 0; k < 3; k++)
//			dp[1][j][k] = INF;
//	cin >> dp[1][0][0] >> dp[1][1][1] >> dp[1][2][2];
//	for (int i = 2; i <= N; i++) {
//		for (int k = 0; k < 3; k++)
//			cin >> RGB[k];
//
//		for (int j = 0; j < 3; j++) 
//			for (int k = 0; k < 3; k++) 
//				dp[i][j][k] = min(dp[i - 1][j][(k + 1) % 3], dp[i - 1][j][(k + 2) % 3]) + RGB[k];
//
//	}
//
//	int result = INF;
//	for (int j = 0; j < 3; j++) {
//		for (int k = 0; k < 3; k++) {
//			if (j == k)	continue;
//			result = result < dp[N][j][k] ? result : dp[N][j][k];
//		}
//	}
//	cout << result;
//	return 0;
//}