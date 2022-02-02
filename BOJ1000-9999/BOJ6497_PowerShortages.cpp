// key point : Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int num;
	int status;
	vector<pair<int, Node*>> adj_list;
	Node(int num) {
		this->num = num;
		this->status = 0;
	}
};

typedef pair<int, Node*> info;

class Graph {
public:
	vector<Node*> node_list;
	Graph(int n) {
		for (int i = 0; i < n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int a, int b, int c) {
		node_list[a]->adj_list.push_back({ c, node_list[b] });
		node_list[b]->adj_list.push_back({ c, node_list[a] });
	}

	int MST(int n) {
		int result = 0;

		priority_queue<info, vector<info>, greater<info>> pq;
		node_list[0]->status = 2;
		for (int i = 0; i < node_list[0]->adj_list.size(); i++) {
			node_list[0]->adj_list[i].second->status = 1;
			pq.push(node_list[0]->adj_list[i]);
		}

		info cur;
		for (int i = 2; i <= n; i++) {
			cur = pq.top();
			pq.pop();
			while (cur.second->status == 2) {
				cur = pq.top();
				pq.pop();
			}

			cur.second->status = 2;
			result += cur.first;
			for (int j = 0; j < cur.second->adj_list.size(); j++) {
				switch (cur.second->adj_list[j].second->status) {
				case 0:
					cur.second->adj_list[j].second->status = 1;
				case 1:
					pq.push(cur.second->adj_list[j]);
				}
			}
		}
		return result;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	while (n != 0 || m != 0) {
		Graph g(n);
		int a, b, c, sum = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			sum += c;
			g.link(a, b, c);
		}
		cout << sum - g.MST(n) << "\n";

		cin >> n >> m;
	}
	return 0;
}