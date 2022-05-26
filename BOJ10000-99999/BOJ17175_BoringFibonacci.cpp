#include <iostream>

using namespace std;

#define MOD 1000000007

int dp[51];

int main() {
	dp[0] = 1;	dp[1] = 1;
	
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;
	
	cout << dp[n];
	return 0;
}