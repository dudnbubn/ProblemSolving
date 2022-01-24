#include <iostream>
#include <algorithm>
using namespace std;

int dp[4001][4001];

int main() {
	string x, y;
	cin >> x >> y;
	
	int result = 0;
	for (int i = 1; i <= x.size(); i++) {
		for (int j = 1; j <= y.size(); j++) {
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				result = max(result, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	cout << result;
	return 0;
}