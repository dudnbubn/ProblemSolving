#include <iostream>

using namespace std;

string s;
int dp[41];

int main() {
	cin >> s;
	s = ' ' + s;

	int num;

	dp[0] = 1;	dp[1] = 1;
	for (int i = 2; i < s.size(); i++) {
		if (s[i] == '0')	dp[i] = dp[i - 2];
		else if (s[i - 1] == '0')	dp[i] = dp[i - 1];
		else {
			num = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (num <= 34)
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1];
		}
	}
	cout << dp[s.size() - 1];

	return 0;
}