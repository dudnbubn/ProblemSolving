#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

struct Node {
	int num;
	bool visited;
	vector<Node*> adj_list;
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
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int a, int b) {
		node_list[a]->adj_list.push_back(node_list[b]);
		node_list[b]->adj_list.push_back(node_list[a]);
	}

	int BFS(int a, int b) {
		int result = -1;
		queue<Node*> q;
		q.push(node_list[a]);
		node_list[a]->visited = true;
		int qsz;
		Node* cur;
		while (!q.empty()) {
			result++;
			qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				cur = q.front();
				q.pop();
				if (cur->num == b)	return result;
				
				for (int j = 0; j < cur->adj_list.size(); j++) {
					if (!cur->adj_list[j]->visited) {
						cur->adj_list[j]->visited = true;
						q.push(cur->adj_list[j]);
					}
				}
			}
		}
		return -1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;
	cin >> n >> m;
	int s, e;
	Graph g;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		g.link(s, e);
	}
	cout << g.BFS(a, b);
	return 0;
}