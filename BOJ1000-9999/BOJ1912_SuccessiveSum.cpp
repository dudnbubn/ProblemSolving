// DP
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int maximum = -1000000000;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[0] = -1000000000;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		maximum = max(dp[i], maximum);
	}
	cout << maximum;
	return 0;
}