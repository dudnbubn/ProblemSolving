#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[101];
int dp[10001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j == arr[i])	dp[j]++;

			if(j >= arr[i])
				dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k];
	return 0;
}