#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 2000000000

int N, Q;
vector<int> result[5001];

struct Node {
	int num;
	bool visited;
	vector<pair<Node*, int>> adj_list;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

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

	void clear() {
		for (int i = 1; i <= N; i++)
			node_list[i]->visited = false;
	}

	void link(int a, int b, int c) {
		node_list[a]->adj_list.push_back({ node_list[b], c });
		node_list[b]->adj_list.push_back({ node_list[a], c });
	}

	void BFS(int start) {
		if (result[start].size())	return;

		clear();

		queue<pair<Node*, int>> q;
		node_list[start]->visited = true;
		q.push({ node_list[start], INF });

		pair<Node*, int> cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();

			result[start].push_back(cur.second);
			for (int i = 0; i < cur.first->adj_list.size(); i++) {
				if (!cur.first->adj_list[i].first->visited) {
					cur.first->adj_list[i].first->visited = true;
					q.push({ cur.first->adj_list[i].first, min(cur.first->adj_list[i].second, cur.second) });
				}
			}
		}
		return;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> Q;
	int a, b, c;
	Graph g;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		g.link(a, b, c);
	}

	int cnt;
	for (int i = 0; i < Q; i++) {
		cnt = -1;
		cin >> a >> b;
		g.BFS(b);
		for (int i = 0; i < result[b].size(); i++) {
			if (result[b][i] >= a)	cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}