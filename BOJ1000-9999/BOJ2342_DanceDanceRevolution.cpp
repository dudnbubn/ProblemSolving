#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1234567891

int dp[100001][5][5];

int get_power(int a, int b) {
	if (a == b)	return 1;
	if (a == 0 || b == 0)	return 2;
	if (a % 2 == b % 2)	return 4;
	return 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 100001; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				dp[i][j][k] = INF;
	
	int N = 0, input;
	dp[0][0][0] = 0;
	cin >> input;
	while (input) {
		N++;
		// 모든 발 위치에 대하여
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				// 왼발 이동
				dp[N][input][j] = min(dp[N][input][j], dp[N - 1][i][j] + get_power(input, i));

				// 오른발 이동
				dp[N][i][input] = min(dp[N][i][input], dp[N - 1][i][j] + get_power(input, j));
			}
		}
		cin >> input;
	}
	
	int result = INF;
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++)
			result = result < dp[N][i][j] ? result : dp[N][i][j];
	cout << result;
	return 0;
}