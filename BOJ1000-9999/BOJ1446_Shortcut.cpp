#include <iostream>
#include <algorithm>

using namespace std;

int n, d;
int dp[10001];
pair<pair<int, int>, int> arr[12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> d;
	for (int i = 0; i <= d; i++)	dp[i] = i;
	for (int i = 0; i < n; i++)	
		cin >> arr[i].first.second >> arr[i].first.first >> arr[i].second;
	sort(arr, arr + n);
	
	for (int i = 0; i <= d; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j].first.first == i) {
				dp[i] = min(dp[i], dp[arr[j].first.second] + arr[j].second);
			}
		}
		for (int j = 0; j < i; j++)
			dp[i] = min(dp[i], dp[j] + i - j);
	}
	cout << dp[d];
	return 0;
}