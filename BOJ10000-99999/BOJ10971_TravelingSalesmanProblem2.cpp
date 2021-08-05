// 전형적인 브루트포스 문제이다.
#include <iostream>
using namespace std;

int n;
int cost[11][11] = { 0, };
bool isUsed[11] = { 0, };
int answer[11];
int minimum = 100000000;

void DFS(int k) {
	if (k == n + 1) {
		if (cost[answer[n]][answer[1]] != 0) {
			int sum = cost[answer[n]][answer[1]];
			for (int i = 1; i < n; i++) {
				sum += cost[answer[i]][answer[i + 1]];
			}
			if (minimum > sum)
				minimum = sum;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isUsed[i]) {
			if ((k != 1) && (cost[answer[k - 1]][i] == 0)) continue;
			isUsed[i] = true;
			answer[k] = i;
			DFS(k + 1);
			isUsed[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> cost[i][j];
	}
	DFS(1);
	cout << minimum;
	return 0;
}