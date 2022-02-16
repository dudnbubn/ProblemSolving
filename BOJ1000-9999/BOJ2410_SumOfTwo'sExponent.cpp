#include <iostream>

using namespace std;

int dp[1000001];

int main() {
	int n; 
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i *= 2) {
		for (int j = i; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - i]) % 1000000000;
		}
	}
	cout << dp[n];
	return 0;
}