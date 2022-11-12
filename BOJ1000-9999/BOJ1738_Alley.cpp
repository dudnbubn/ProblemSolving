#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

#define INF 987654321

int N, M;
int prevs[101];
int matrix[101][101];
int dist[101];
bool valid[101];
bool visited[101][101];

bool DFS(int start) {
	if (start == N)	return true;

	bool result = false;
	for (int i = 1; i <= N; i++) {
		if (visited[start][i] || matrix[start][i] == INF)	continue;
		visited[start][i] = true;
		result |= DFS(i);
	}
	return valid[start] = result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		for (int j = 1; j <= N; j++)
			matrix[i][j] = INF;
	}

	int u, v, w;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v >> w;
		w *= -1;
		matrix[u][v] = matrix[u][v] < w ? matrix[u][v] : w;
	}

	DFS(1);

	dist[1] = 0;
	for (int k = 1; k < N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i] == INF || matrix[i][j] == INF)	continue;
				if (dist[j] > dist[i] + matrix[i][j]) {
					dist[j] = dist[i] + matrix[i][j];
					prevs[j] = i;
				}
			}
		}
	}
	

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i] == INF || matrix[i][j] == INF)	continue;
			if (dist[j] > dist[i] + matrix[i][j]) {
				dist[j] = dist[i] + matrix[i][j];
				prevs[j] = i;
				if (valid[j])	flag = true;
			}
		}
	}

	if (flag)	cout << -1;
	else {
		stack<int> result;
		int cur = N;
		while (cur != 0) {
			result.push(cur);
			cur = prevs[cur];
		}

		while (!result.empty()) {
			cout << result.top() << " ";
			result.pop();
		}
	}
	return 0;
}