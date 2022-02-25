#include <iostream>
#include <algorithm>

using namespace std;

int n;
int score[1001];
int gap[1001][1001];
int dp[1001];

int main() {
	cin >> n;
	int minimum, maximum;
	for (int i = 1; i <= n; i++)	cin >> score[i];
	for (int i = 1; i <= n; i++) {
		minimum = score[i];	maximum = score[i];
		for (int j = i; j <= n; j++) {
			minimum = min(minimum, score[j]);
			maximum = max(maximum, score[j]);
			gap[i][j] = maximum - minimum;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + gap[j + 1][i]);
		}
	}
	cout << dp[n];
	return 0;
}