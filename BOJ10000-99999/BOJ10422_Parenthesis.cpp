#include <iostream>

using namespace std;

#define DIV 1000000007
long long dp[2501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0] = 1;	dp[1] = 1;
	for (int i = 2; i <= 2500; i++)
		for (int j = 0; j < i; j++)
			dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % DIV;

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (n % 2 == 0 ? dp[n / 2] : 0) << "\n";
	}
	return 0;
}