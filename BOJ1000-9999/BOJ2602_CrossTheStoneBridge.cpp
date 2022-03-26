#include <iostream>

using namespace std;

long long dp[21][2][101];
string str;
string bridge[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	cin >> bridge[0] >> bridge[1];

	long long result = 0;

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < bridge[i].size(); j++)
			if (bridge[i][j] == str[0]) {
				dp[0][i][j] = 1;
				if (str.size() == 1) {
					result++;
				}
			}

	for (int s = 1; s < str.size(); s++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < bridge[i].size(); j++) {
				if (bridge[i][j] == str[s]) {
					for (int k = 0; k < j; k++) {
						if (bridge[(i + 1) % 2][k] == str[s - 1]) {
							dp[s][i][j] += dp[s - 1][(i + 1) % 2][k];
						}
					}
					if (s == str.size() - 1)	result += dp[s][i][j];
				}
			}
		}
	}
	cout << result;
	return 0;
}