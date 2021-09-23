#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
	cin >> n;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)	dp[i] = 2000;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= i + arr[i] && j <= n; j++)
			dp[j] = min(dp[j], dp[i] + 1);
	}
	if (dp[n] == 2000)	cout << -1;
	else	cout << dp[n];
	return 0;
}