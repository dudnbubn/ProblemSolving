// key point : Dijkstra

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int num;
	int status;
	vector<pair<Node*, int>> adj_list;
	Node(int num) {
		this->num = num;
		this->status = 0;
	}
};

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

	void link(int a, int b, int s) {
		node_list[b]->adj_list.push_back({ node_list[a], s });
	}

	void Dijkstra(int start){
		priority_queue < pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
		pq.push({ 0, node_list[start] });
		pair<int, Node*> cur;

		int cnt = 0, maximum = 0;
		bool flag = false;
		while (!pq.empty()) {
			cur = pq.top();
			pq.pop();
			while (cur.second->status == 2) {
				if (pq.empty()) {
					flag = true;
					break;
				}
				cur = pq.top();
				pq.pop();
			}
			if (flag) break;
			cnt++;
			cur.second->status = 2;
			maximum = max(maximum, cur.first);
			for (int i = 0; i < cur.second->adj_list.size(); i++) {
				switch (cur.second->adj_list[i].first->status) {
				case 0:
					cur.second->adj_list[i].first->status = 1;
				case 1:
					pq.push({ cur.first + cur.second->adj_list[i].second, cur.second->adj_list[i].first });
				}
			}
		}
		cout << cnt << " " << maximum << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	int n, d, c, a, b, s;
	while (t--) {
		cin >> n >> d >> c;
		Graph g(n);
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			g.link(a, b, s);
		}

		g.Dijkstra(c);
	}
	return 0;
}