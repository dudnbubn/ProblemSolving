#include <iostream>

using namespace std;

int n;
double percentage[4];
int visited[30][30];
double result = 0;
int di[4] = { 0, 0, -1, 1 };
int dj[4] = { 1, -1, 0, 0 };

void DFS(int k, int cur_i, int cur_j, double val) {
	if (k == n) {
		result += val;
		return;
	}
	int next_i, next_j;
	for (int i = 0; i < 4; i++) {
		next_i = cur_i + di[i];
		next_j = cur_j + dj[i];
		if (!visited[next_i][next_j]) {
			visited[next_i][next_j] = true;
			DFS(k + 1, next_i, next_j, val * percentage[i]);
			visited[next_i][next_j] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> percentage[i];
		percentage[i] /= 100;
	}
	visited[15][15] = true;
	DFS(0, 15, 15, 1);
	cout.precision(10);
	cout << fixed << result;
	return 0;
}