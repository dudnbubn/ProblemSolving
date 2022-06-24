#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, E;
long long dist[3][801];

#define INF 2100000000

struct Node {
	int num;
	bool visited;
	vector<pair<int, Node*>> adj_list;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

typedef pair<int, Node*> info;
priority_queue<info, vector<info>, greater<info>> pq;

class Graph {
public:
	vector<Node*> node_list;
	Graph() {
		node_list.push_back(0);
		for (int i = 1; i <= N; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int a, int b, int c) {
		node_list[a]->adj_list.push_back({ c, node_list[b] });
		node_list[b]->adj_list.push_back({ c, node_list[a] });
	}

	void clear() {
		pq = {};
		for (int i = 1; i <= N; i++)
			node_list[i]->visited = false;
	}

	void Dijkstra(int start, int index) {
		clear();
		pq.push({ 0, node_list[start] });

		info cur;
		for (int i = 1; !pq.empty() && i <= N; i++) {
			cur = pq.top();
			pq.pop();
			while (cur.second->visited) {
				cur = pq.top();
				pq.pop();
			}
			
			dist[index][cur.second->num] = cur.first;
			cur.second->visited = true;

			for (info i : cur.second->adj_list) {
				if (!i.second->visited) {
					pq.push({ cur.first + i.first, i.second });
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> E;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 801; j++)
			dist[i][j] = INF;

	Graph g;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		g.link(a, b, c);
	}

	int v1, v2;
	cin >> v1 >> v2;
	g.Dijkstra(1, 0);
	g.Dijkstra(v1, 1);
	g.Dijkstra(v2, 2);

	long long route1 = 0, route2 = 0;
	route1 = dist[0][v1] + dist[1][v2] + dist[2][N];
	route2 = dist[0][v2] + dist[2][v1] + dist[1][N];
	
	if (route1 >= INF && route2 >= INF)	cout << -1;
	else	cout << (route1 < route2 ? route1 : route2);
	return 0;
}