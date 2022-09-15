#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> adj_list[3001];
int degrees[3001];

int result[3001];
bool visited[3001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
		degrees[a]++;
		degrees[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degrees[i] == 1)
			q.push(i);
	}
	
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int adj : adj_list[cur]) {
			if (degrees[adj] > 1) {
				degrees[adj]--;
				if (degrees[adj] == 1)
					q.push(adj);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (degrees[i] > 1) {
			result[i] = 0;
			visited[i] = true;
			q.push(i);
		}
	}

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int adj : adj_list[cur]) {
			if (visited[adj])	continue;
			visited[adj] = true;
			result[adj] = result[cur] + 1;
			q.push(adj);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] << " ";
	return 0;
}