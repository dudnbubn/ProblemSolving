#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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
	Graph(int n) {
		this->node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int a, int b) {
		node_list[a]->adj_list.push_back(node_list[b]);
		node_list[b]->adj_list.push_back(node_list[a]);
	}

	void reset() {
		for (int i = 1; i < node_list.size(); i++)
			node_list[i]->visited = false;
	}

	int BFS(int start) {
		int result = -1;
		queue<Node*> q;
		q.push(node_list[start]);
		node_list[start]->visited = true;
		while (!q.empty()) {
			result++;
			int qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				Node* cur = q.front();
				q.pop();
				for (int j = 0; j < cur->adj_list.size(); j++) {
					if (!cur->adj_list[j]->visited) {
						cur->adj_list[j]->visited = true;
						q.push(cur->adj_list[j]);
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

	int n;
	cin >> n;
	Graph g(n);
	int a, b;
	cin >> a >> b;
	while (a != -1 && b != -1) {
		g.link(a, b);
		cin >> a >> b;
	}
	int minimum = (1 << 31) - 1;
	int bfs[51];
	for (int i = 1; i <= n; i++) {
		g.reset();
		bfs[i] = g.BFS(i);
		minimum = min(minimum, bfs[i]);
	}
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (bfs[i] == minimum)	result.push_back(i);
	}
	cout << minimum << " " << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}