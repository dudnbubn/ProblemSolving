#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

struct Node {
	int num;
	int status;
	vector<pair<int, Node*>> adj_list;
	Node(int num) {
		this->num = num;
		this->status = 0;
	}
};

class Graph {
public:
	vector<Node*> node_list;
	Graph() {
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
	
	int getWeight(int start, int end) {
		priority_queue<pair<int, Node*>, vector<pair<int, Node*>>> pq;
		pq.push({ 1000000000, node_list[start] });
		pair<int, Node*> cur;
		for (int i = 1; i <= n; i++) {
			cur = pq.top();
			pq.pop();
			while (cur.second->status == 2) {
				cur = pq.top();
				pq.pop();
			}
			
			if (cur.second->num == end)
				return cur.first;
			cur.second->status = 2;
			
			for (int j = 0; j < cur.second->adj_list.size(); j++) {
				switch (cur.second->adj_list[j].second->status) {
				case 0:
					cur.second->adj_list[j].second->status = 1;
				case 1:
					pq.push({ min(cur.first, cur.second->adj_list[j].first), cur.second->adj_list[j].second });
				}
			}
		}
	}
};
int main() {
	cin >> n >> m;
	
	Graph g;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g.link(a, b, c);
	}
	int start, end;
	cin >> start >> end;
	cout << g.getWeight(start, end);
	return 0;
}