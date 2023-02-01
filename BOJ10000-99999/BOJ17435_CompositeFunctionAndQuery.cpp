// key point : sparse table

#include <iostream>

using namespace std;

int M, Q, N, X;
int dp[20][200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M;
	for (int i = 1; i <= M; i++)	cin >> dp[1][i];
	for (int i = 2; i < 20; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> N >> X;
		for (int j = 1; j < 20; j++) {
			if (N & 1)	X = dp[j][X];
			N /= 2;
		}
		cout << X << "\n";
	}
	return 0;
}