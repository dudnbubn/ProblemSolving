#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	string a, b, result = "";
	cin >> a >> b;
	int len = 0;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int r = a.size(), c = b.size();
	for (int i = 0; i < dp[a.size()][b.size()];) {
		if (dp[r][c] == dp[r - 1][c]) 
			r--;
		else if (dp[r][c] == dp[r][c - 1])
			c--;
		else {
			r--;
			c--;
			result = a[r] + result;
			i++;
		}
	}
	cout << dp[a.size()][b.size()] << "\n" << result;
	return 0;
}