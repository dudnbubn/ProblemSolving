#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int num;
	int dist;
	bool visited;
	vector<Node*> adj_list;
	Node(int num) {
		this->num = num;
		this->dist = 0;
		this->visited = false;
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

	void link(int a, int b) {
		node_list[a]->adj_list.push_back(node_list[b]);
		node_list[b]->adj_list.push_back(node_list[a]);
	}

	int BFS() {
		int result = -1;
		queue<Node*> q;
		node_list[1]->visited = true;
		q.push(node_list[1]);
		Node* cur;
		while (!q.empty()) {
			result++;
			int qsz = q.size();
			for (int j = 0; j < qsz; j++) {
				cur = q.front();
				q.pop();
				for (int i = 0; i < cur->adj_list.size(); i++) {
					if (!cur->adj_list[i]->visited) {
						cur->adj_list[i]->visited = true;
						cur->adj_list[i]->dist = cur->dist + 1;
						q.push(cur->adj_list[i]);
					}
				}
			}
		}
		return result;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	Graph g(n);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g.link(a, b);
	}
	int dist = g.BFS();
	int cnt = 0;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (g.node_list[i]->dist == dist) {
			cnt++;
			if (flag) {
				cout << i << " " << dist << " ";
				flag = false;
			}
		}
	}
	cout << cnt;
	return 0;
}