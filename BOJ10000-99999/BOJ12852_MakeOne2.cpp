#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int dp[1000001];
int before[1000001];
stack<int> result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				before[i] = i / 2;
			}
			
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				before[i] = i / 3;
			}
		}
	}
	before[1] = 0;
	cout << dp[n] << "\n";
	int index = n;
	while (index > 0) {
		cout << index << " ";
		index = before[index];
	}
	return 0;
}