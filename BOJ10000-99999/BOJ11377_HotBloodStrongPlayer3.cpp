#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> adj_list[1001];
int limits[1001];
int visited[1001];
int workers[1001];

bool DFS(int current) {
	if (visited[current] >= limits[current])	return false;
	visited[current]++;

	for (int adj : adj_list[current]) {
		if (!workers[adj] || DFS(workers[adj])) {
			workers[adj] = current;
			return true;
		}
	}
	return false;
}

void init_visited() {
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	int cnt, work;
	for (int i = 1; i <= N; i++) {
		cin >> cnt;
		limits[i] = 1;
		for (int j = 0; j < cnt; j++) {
			cin >> work;
			adj_list[i].push_back(work);
		}
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++) {
		init_visited();
		if (DFS(i))	result++;
	}

	for (int i = 1; i <= N && K; i++) {
		limits[i] = 2;
		init_visited();
		if (DFS(i)) {
			result++;
			K--;
		}
		limits[i] = 1;
	}

	cout << result;
	return 0;
}