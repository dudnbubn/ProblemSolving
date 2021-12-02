// Kruskal Algorithm

#include <iostream>
#include <queue>
using namespace std;

int parent[10001];

struct Edge {
	int v;
	int w;
	int weight;
	Edge(int v, int w, int weight) {
		this->v = v;
		this->w = w;
		this->weight = weight;
	}
};

struct compare {
	bool operator()(Edge & a, Edge & b) {
		return a.weight > b.weight;
	}
};

int find(int x) {
	if (x == parent[x])
		return x;
	return find(parent[x]);
}

void unionVW(int v, int w) {
	v = find(v);
	w = find(w);

	parent[w] = v;
}

priority_queue<Edge, vector<Edge>, compare> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, a, b, c;
	cin >> v >> e;

	for (int i = 1; i <= v; i++)	parent[i] = i;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		pq.push(Edge(a, b, c));
	}
	
	int cnt = 0;
	int result = 0;
	while (cnt < v - 1) {
		Edge edge = pq.top();
		pq.pop();
		if (find(edge.v) != find(edge.w)) {
			result += edge.weight;
			unionVW(edge.v, edge.w);
			cnt++;
		}
	}

	cout << result;
	return 0;
}