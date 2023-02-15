#include <iostream>
#include <vector>

using namespace std;

#define LIMIT 2

int N, M;
vector<int> adj_list[1001];
int visited[1001];
int workers[1001];

bool DFS(int node) {
	if (visited[node] >= LIMIT)	return false;
	visited[node]++;
	for (int adj : adj_list[node]) {
		if (!workers[adj] || DFS(workers[adj])) {
			workers[adj] = node;
			return true;
		}
	}
	return false;
}

void visited_clear() {
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int cnt, work;
	for (int i = 1; i <= N; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> work;
			adj_list[i].push_back(work);
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			visited_clear();
			if(DFS(i))	result++;
		}
	}
	cout << result;

	return 0;	
}