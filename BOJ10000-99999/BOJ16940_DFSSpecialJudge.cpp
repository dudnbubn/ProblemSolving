#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
int priority[100001];
bool visited[100001];
vector<int> adj_list[100001];
queue<int> q;

bool compare(int a, int b) {
	return priority[a] < priority[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		priority[input] = i;
	}
	
	for (int i = 1; i <= N; i++)
		sort(adj_list[i].begin(), adj_list[i].end(), compare);

	bool result = true;

	q.push(1);
	visited[1] = true;

	int cur, index = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (priority[cur] != index) {
			result = false;
			break;
		}

		index++;
		
		for (int adj : adj_list[cur]) {
			if (visited[adj])	continue;
			visited[adj] = true;
			q.push(adj);
		}
	}
	
	cout << (result ? 1 : 0);
	return 0;
}