#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000

int dp[101][10][1<<10];	// [길이][끝나는 수][방문]
vector<vector<int>> adj_list = { {1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}, {7, 9}, {8} };

int main() {
	int N;
	cin >> N;

	for (int i = 1; i < 10; i++)	dp[1][i][1<<i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int adj : adj_list[j]) {
				for (int k = 0; k < (1 << 10); k++) {
					dp[i][adj][k | (1 << adj)] = (dp[i][adj][k | (1 << adj)] + dp[i - 1][j][k]) % MOD;
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++) 
		result = (result + dp[N][i][(1 << 10) - 1]) % MOD;
	cout << result;

	return 0;
}