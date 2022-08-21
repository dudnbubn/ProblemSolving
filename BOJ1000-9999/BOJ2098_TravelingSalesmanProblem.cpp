#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VALUE 1e9;

int N;
int W[16][16];
int dp[65536][16];

int TSP(int state, int cur) {
	state |= (1 << cur);

	if (state == (1 << N) - 1) {
		if (W[cur][0] > 0)
			return W[cur][0];
		else
			return MAX_VALUE;
	}

	if (dp[state][cur] > 0)	return dp[state][cur];

	dp[state][cur] = MAX_VALUE;

	for (int i = 0; i < N; i++) {
		if (i == cur)	continue;

		if ((state & (1 << i)) == 0 && W[cur][i] != 0)
			dp[state][cur] = min(dp[state][cur], TSP(state, i) + W[cur][i]);
	}
	
	return dp[state][cur];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	cout << TSP(0, 0);

	return 0;
}