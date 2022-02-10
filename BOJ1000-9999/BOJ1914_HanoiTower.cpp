#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string dp[101];
vector<pair<int, int>> v[21];

string moveCount(string s) {
	int value, carry = 1, sum;
	string result = "";
	for (int index = s.size() - 1; index >= 0; index--) {
		value = s[index] - '0';
		sum = value * 2 + carry;
		carry = sum / 10;
		sum %= 10;
		result = (char)(sum + '0') + result;
	}
	if (carry > 0)
		result = (char)(carry + '0') + result;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	dp[1] = "1";
	for (int i = 2; i <= n; i++)
		dp[i] = moveCount(dp[i - 1]);
	if (n <= 20) {
		v[1].push_back({ 1, 3 });
		int fir, sec;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < v[i - 1].size(); j++) {
				fir = v[i - 1][j].first;
				sec = v[i - 1][j].second;
				if (fir == 2)	fir = 3;
				else if (fir == 3)	fir = 2;
				if (sec == 3)	sec = 2;
				else if (sec == 2)	sec = 3;
				v[i].push_back({ fir, sec });
			}
			v[i].push_back({ 1,3 });
			for (int j = 0; j < v[i - 1].size(); j++) {
				fir = v[i - 1][j].first;
				sec = v[i - 1][j].second;
				if (fir == 1)	fir = 2;
				else if (fir == 2)	fir = 1;
				if (sec == 1)	sec = 2;
				else if (sec == 2)	sec = 1;
				v[i].push_back({ fir, sec });
			}
		}
		cout << dp[n] << "\n";
		for (int i = 0; i < v[n].size(); i++) {
			cout << v[n][i].first << " " << v[n][i].second << "\n";
		}
	}
	else {
		cout << dp[n];
	}
	return 0;
}