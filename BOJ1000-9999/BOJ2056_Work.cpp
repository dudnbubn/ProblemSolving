#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	int cnt;
	int before;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i] >> cnt;
		int maximum = 0;
		for (int j = 0; j < cnt; j++) {
			cin >> before;
			maximum = max(maximum, dp[before]);
		}
		if (cnt == 0)	dp[i] = arr[i];
		else	dp[i] = maximum + arr[i];
	}
	
	int result = 0;
	for (int i = 1; i <= n; i++)
		result = max(result, dp[i]);
	cout << result;

	return 0;
}