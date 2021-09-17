#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int comp[10001];


struct Node {
	int data;
	bool visited;
	vector<Node*> linked;
	Node(int data) {
		this->data = data;
		this->visited = false;
	}
};

queue<Node*> q;

class Network {
public:
	vector<Node*> node_list;
	Network(int n) {
		node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int x, int y) {
		node_list[y]->linked.push_back(node_list[x]);
	}
	
	int BFS(Node* node) {
		while (!q.empty())	q.pop();
		for (int i = 1; i < node_list.size(); i++)	node_list[i]->visited = false;

		int cnt = 0;
		node->visited = true;
		q.push(node);
		while (!q.empty()) {
			int qsz = q.size();
			cnt += qsz;
			for (int i = 0; i < qsz; i++) {
				Node* cur = q.front();
				q.pop();
				for (int j = 0; j < cur->linked.size(); j++) {
					if (!cur->linked[j]->visited) {
						cur->linked[j]->visited = true;
						q.push(cur->linked[j]);
					}
				}
			}
		}
		return cnt;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int maximum = 0;
	int n, m, x, y;
	cin >> n >> m;
	Network nw(n);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		nw.link(x, y);
	}
	for (int i = 1; i <= n; i++) {
		comp[i] = nw.BFS(nw.node_list[i]);
		maximum = max(maximum, comp[i]);
	}
	for (int i = 1; i <= n; i++)
		if (comp[i] == maximum)
			cout << i << " ";
	return 0;
}