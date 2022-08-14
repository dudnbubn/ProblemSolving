#include <iostream>
#include <algorithm>

using namespace std;

int arr[501];
int subsum[501][501];
int dp[501][501];

#define MAX_VALUE 2147483647

int func(int start, int end) {
	if (start == end)	return 0;
	if (dp[start][end] != MAX_VALUE)	return dp[start][end];

	for (int i = start; i < end; i++)
		dp[start][end] = min(dp[start][end], subsum[start][end] + func(start, i) + func(i + 1, end));

	return dp[start][end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				subsum[i][j] = subsum[i][j - 1] + arr[j];
				dp[i][j] = MAX_VALUE;
			}
		}
		
		cout << func(1, N) << "\n";
	}

	return 0;
}