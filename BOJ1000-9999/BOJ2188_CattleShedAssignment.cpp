#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> adj_list[201];
bool visited[201];
int linked[201];

bool DFS(int node) {
	if (visited[node])	return false;
	visited[node] = true;

	for (int adj : adj_list[node]) {
		if (!linked[adj] || DFS(linked[adj])) {
			linked[adj] = node;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int S, x;
	for (int i = 1; i <= N; i++) {
		cin >> S;
		for (int j = 0; j < S; j++) {
			cin >> x;
			adj_list[i].push_back(x);
		}
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	visited[j] = false;
		if (DFS(i))	result++;
	}
	cout << result;
	return 0;
}