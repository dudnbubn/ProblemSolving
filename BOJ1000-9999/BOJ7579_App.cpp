#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int m[101];
int c[101];
int knapsack[10001][101];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> m[i];
	for (int i = 1; i <= N; i++)	cin >> c[i];

	int result = 10000;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 10000; j++) {
			if (j >= c[i]) {
				if (m[i] + knapsack[j - c[i]][i - 1] > knapsack[j][i - 1])
					knapsack[j][i] = m[i] + knapsack[j - c[i]][i - 1];
				else	knapsack[j][i] = knapsack[j][i - 1];
			}
			else	knapsack[j][i] = knapsack[j][i - 1];

			if (knapsack[j][i] >= M)
				result = result < j ? result : j;
		}
	}
	cout << result;
	return 0;
}