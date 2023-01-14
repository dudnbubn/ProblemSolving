#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int parents[101];
bool visited[101];
vector<int> adj_list[101];

unordered_set<int> us;
vector<int> representative;

int Find(int x) {
	if (x == parents[x])	return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	parents[y] = x;
}

int Dijkstra(int start) {
	for (int i = 1; i <= N; i++)	visited[i] = false;
	int result = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, start });
	pair<int, int> cur;
	int weight, node;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		
		weight = cur.first;
		node = cur.second;
		if (visited[node])	continue;

		visited[node] = true;
		result = result > weight ? result : weight;
		for (int adj : adj_list[node]) {
			if (visited[adj])	continue;
			 
			pq.push({ weight + 1, adj });
		}
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)	parents[i] = i;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);

		if (Find(a) != Find(b))	Union(a, b);
	}

	int dijkstra = 0;
	
	for (int i = 1; i <= N; i++) {
		if (us.find(Find(i)) != us.end())	continue;
		int minimum = 100;
		int index = i;
		for (int j = 1; j <= N; j++) {
			if (Find(i) != Find(j))	continue;
			dijkstra = Dijkstra(j);
			if (minimum > dijkstra) {
				minimum = dijkstra;
				index = j;
			}
		}
		representative.push_back(index);
		us.insert(Find(i));
	}

	sort(representative.begin(), representative.end());

	cout << representative.size() << "\n";
	for (int repre : representative) 
		cout << repre << "\n";

	return 0;
}