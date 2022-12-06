#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> x_position[100001];
pair<int, int> y_position[100001];
pair<int, int> z_position[100001];

typedef pair<int, pair<int, int>> Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int parent[100001];

int Find(int x) {
	if (x == parent[x])	return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	
	parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int x, y, z;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		parent[i + 1] = i + 1;
		x_position[i] = { x, i + 1 };
		y_position[i] = { y, i + 1 };
		z_position[i] = { z, i + 1 };
	}

	sort(x_position, x_position + N);
	sort(y_position, y_position + N);
	sort(z_position, z_position + N);

	for (int i = 0; i < N - 1; i++) {
		pq.push({ x_position[i + 1].first - x_position[i].first, {x_position[i + 1].second, x_position[i].second} });
		pq.push({ y_position[i + 1].first - y_position[i].first, {y_position[i + 1].second, y_position[i].second} });
		pq.push({ z_position[i + 1].first - z_position[i].first, {z_position[i + 1].second, z_position[i].second} });
	}
	
	long long result = 0;

	Edge edge;
	int weight, u, v;
	for (int i = 0; i < N - 1; ) {
		edge = pq.top();
		pq.pop();
		
		weight = edge.first;
		u = edge.second.first;
		v = edge.second.second;
		if (Find(u) == Find(v))	continue;
		i++;
		result += weight;
		Union(u, v);
	}

	cout << result;
	return 0;
}