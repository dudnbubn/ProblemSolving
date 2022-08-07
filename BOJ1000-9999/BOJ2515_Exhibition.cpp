#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_HEIGHT 20000000

int value[MAX_HEIGHT + 1];
int dp[MAX_HEIGHT + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, S;
	cin >> N >> S;
	int maximum = 0;
	int H, C;
	for (int i = 0; i < N; i++) {
		cin >> H >> C;
		value[H] = max(value[H], C);
		maximum = maximum > H ? maximum : H;
	}

	for (int i = S; i <= maximum; i++) {
		dp[i] = max(dp[i - 1], dp[i - S] + value[i]);
	}
	cout << dp[maximum];

	return 0;
}