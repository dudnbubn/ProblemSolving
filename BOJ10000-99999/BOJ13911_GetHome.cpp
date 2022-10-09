#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 3e9+1

bool visited[10001];
long long dist_M[10001], dist_S[10001];
vector<pair<int, int>> adj_list[10001];
vector<int> mcdonalds, starbucks;

struct Node {
public:
	long long weight;
	int number;

	Node() {}

	Node(long long weight, int number) {
		this->weight = weight;
		this->number = number;
	}
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.weight > b.weight;
	}
};

priority_queue<Node, vector<Node>, compare> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, E;
	cin >> V >> E;
	
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj_list[u].push_back({ v, w });
		adj_list[v].push_back({ u, w });
	}

	int M, x, S, y, input;
	cin >> M >> x;
	for (int i = 0; i < M; i++) {
		cin >> input;
		mcdonalds.push_back(input);
	}
	cin >> S >> y;
	for (int i = 0; i < S; i++) {
		cin >> input;
		starbucks.push_back(input);
	}
	
	for (int i = 1; i <= V; i++) 
		dist_M[i] = dist_S[i] = INF;

	Node cur;
	long weight;
	int number;

	for (int mcdonald : mcdonalds)	pq.push(Node(0, mcdonald));
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		weight = cur.weight;
		number = cur.number;
		if (visited[number])	continue;

		visited[number] = true;
		dist_M[number] = weight;

		for (pair<int, int> adj : adj_list[number]) {
			if (visited[adj.first])	continue;
			pq.push(Node(weight + adj.second, adj.first));
		}
	}

	for (int i = 1; i <= V; i++)	visited[i] = false;
	for (int starbuck : starbucks)	pq.push(Node(0, starbuck));
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		weight = cur.weight;
		number = cur.number;
		if (visited[number])	continue;

		visited[number] = true;
		dist_S[number] = weight;

		for (pair<int, int> adj : adj_list[number]) {
			if (visited[adj.first])	continue;
			pq.push(Node(weight + adj.second, adj.first));
		}
	}

	long long result = 2 * INF, sum;

	for (int i = 1; i <= V; i++) {
		if (dist_M[i] > x || dist_S[i] > y)	continue;
		if (dist_M[i] == 0 || dist_S[i] == 0)	continue;

		sum = dist_M[i] + dist_S[i];
		result = result < sum ? result : sum;
	}

	cout << (result < 2 * INF ? result : -1);

	return 0;
}