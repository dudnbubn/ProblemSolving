#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> adj_list[10001];
int in_degree[10001];
int weights[10001];
vector<int> prevs[10001];

queue<pair<int, int>> q;
bool visited[10001];

int get_edge_count(int number) {
	if (visited[number])	return 0;
	visited[number] = true;
	int result = prevs[number].size();
	
	for (int prev : prevs[number])
		result += get_edge_count(prev);

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj_list[a].push_back({ c, b });
		in_degree[b]++;
	}

	int start, end;
	cin >> start >> end;

	q.push({ 0, start });

	pair<int, int> current;
	int weight, number;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		weight = current.first;
		number = current.second;

		for (pair<int, int> adj : adj_list[number]) {
			int next = adj.second;
			in_degree[next]--;

			if (weights[next] < weight + adj.first) {
				weights[next] = weight + adj.first;
				prevs[next] = {};
				prevs[next].push_back(number);
			}
			else if (weights[next] == weight + adj.first) {
				prevs[next].push_back(number);
			}

			if (!in_degree[next])	q.push({ weights[next], next});
		}
	}

	int result = get_edge_count(end);

	cout << weights[end] << "\n" << result;
	return 0;
}