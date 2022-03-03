#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dist[100001];

struct Node {
	int num;
	int status;
	vector<pair<int, Node*>> adj_list;
	Node(int num) {
		this->num = num;
		this->status = 0;
	}
};

typedef pair<pair<int, int>, Node*> info;

class Graph {
public:
	vector<Node*> node_list;

	Graph(int n) {
		node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int a, int b, int c) {
		node_list[a]->adj_list.push_back({ c, node_list[b] });
		node_list[b]->adj_list.push_back({ c, node_list[a] });
	}

	int Dijkstra(int n, int robot1, int robot2) {
		priority_queue<info, vector<info>, greater<info>> pq;
		pq.push({ {0, 0}, node_list[robot1] });

		info cur;
		pair<int, Node*> adj;
		for (int i = 1; i <= n; i++) {
			cur = pq.top();
			pq.pop();
			while (cur.second->status == 2) {
				cur = pq.top();
				pq.pop();
			}
			
			cur.second->status = 2;
			dist[cur.second->num] = cur.first.first - cur.first.second;
			if (cur.second->num == robot2)
				return dist[robot2];
			
			for (int j = 0; j < cur.second->adj_list.size(); j++) {
				adj = cur.second->adj_list[j];
				switch (adj.second->status) {
				case 0:
					adj.second->status = 1;
				case 1:
					pq.push({ {cur.first.first + adj.first, max(cur.first.second, adj.first)}, adj.second });
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, robot1, robot2, a, b, c;
	cin >> n >> robot1 >> robot2;

	Graph g(n);
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		g.link(a, b, c);
	}
	cout << g.Dijkstra(n, robot1, robot2);
	return 0;
}