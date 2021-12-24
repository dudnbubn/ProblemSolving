#include <iostream>
using namespace std;

int code[5001];
int dp[5001][2] = { 0, };

int main() {
	string s;
	cin >> s;
	if (s[0] == '0') {
		cout << 0;
		return 0;
	}
	int n = s.size();
	for (int i = 1; i <= n; i++)	code[i] = (s[i - 1] - '0');

	dp[1][0] = 1;
	dp[1][1] = 0;
	int num;
	for (int i = 2; i <= n; i++) {
		num = code[i - 1] * 10 + code[i];
		if (code[i] == 0) {
			if (num <= 26)
				dp[i][1] = dp[i - 1][0];
		}
		else {
			if (num <= 26) {
				dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
				dp[i][1] = dp[i - 1][0];
			}
			else {
				dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
			}
		}
	}

	cout << (dp[n][0] + dp[n][1]) % 1000000;

	return 0;
}