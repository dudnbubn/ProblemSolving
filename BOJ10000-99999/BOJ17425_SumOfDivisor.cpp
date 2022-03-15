#include <iostream>

using namespace std;

int input[100000];
long long dp[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	
	int range = 0;
	
	for (int i = 0; i < t; i++) {
		cin >> input[i];
		range = range > input[i] ? range : input[i];
	}
	
	for (int i = 1; i <= range; i++) 
		for (int j = 1; j * i <= range; j++) 
			dp[j * i] += i;
	
	for (int i = 2; i <= range; i++)	dp[i] += dp[i - 1];
	
	for (int i = 0; i < t; i++)
		cout << dp[input[i]] << '\n';

	return 0;
}