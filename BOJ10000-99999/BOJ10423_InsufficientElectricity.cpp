#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[1000];

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

	int MST() {
		int result = 0;
		priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
		for (int i = 0; i < k; i++)		pq.push({ 0, node_list[arr[i]] });

		pair<int, Node*> cur, next;
		for (int i = 0; i < n; i++) {
			cur = pq.top();
			pq.pop();
			while (cur.second->status == 2) {
				cur = pq.top();
				pq.pop();
			}
			
			result += cur.first;
			cur.second->status = 2;
			for (int j = 0; j < cur.second->adj_list.size(); j++) {
				next = cur.second->adj_list[j];
				switch (next.second->status) {
				case 0:
					next.second->status = 1;
				case 1:
					pq.push(next);
				}
			}
		}
		return result;
	}
	
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	Graph g;
	for (int i = 0; i < k; i++) cin >> arr[i];
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g.link(a, b, c);
	}
	cout << g.MST();
	return 0;
}