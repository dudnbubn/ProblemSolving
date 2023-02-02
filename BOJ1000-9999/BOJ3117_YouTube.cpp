// key point : sparse table

#include <iostream>

using namespace std;

int N, K, M;
int dp[31][100001];
int numbers[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K >> M;

	for (int i = 1; i <= N; i++)	cin >> numbers[i];
	for (int i = 1; i <= K; i++)	cin >> dp[0][i];
	
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}

	M--;
	int index = 0;
	while (M) {
		if (M & 1) {
			for (int i = 1; i <= N; i++)
				numbers[i] = dp[index][numbers[i]];
		}
		index++;
		M /= 2;
	}

	for (int i = 1; i <= N; i++)
		cout << numbers[i] << " ";
	return 0;
}