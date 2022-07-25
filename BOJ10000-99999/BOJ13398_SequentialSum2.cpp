#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001][2];

#define MIN_VALUE -987654321;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][0] = dp[i][1] = MIN_VALUE;
	}

	int result = arr[1];

	dp[1][0] = arr[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i-1][0] <= 0) 
			dp[i][0] = arr[i];
		else 
			dp[i][0] = dp[i - 1][0] + arr[i];
		
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);

		result = max(result, max(dp[i][0], dp[i][1]));
	}

	cout << result;


	return 0;
}