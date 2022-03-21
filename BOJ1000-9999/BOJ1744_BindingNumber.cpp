#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[51];
long long dp[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	dp[1] = arr[1];
	dp[2] = max(arr[1] + arr[2], arr[1] * arr[2]);
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i - 1] * arr[i], dp[i - 1] + arr[i]);
	}
	cout << dp[n];
	return 0;
}