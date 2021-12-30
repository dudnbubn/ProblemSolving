#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int num;
	int height;
	bool visited;
	Node* parent;
	vector<Node*> adj_list;
	Node(int num) {
		this->num = num;
		this->height = 0;
		this->visited = false;
		this->parent = NULL;
	}
};

class Tree {
public:
	vector<Node*> node_list;
	Tree(int n) {
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

	void BFS() {
		queue<Node*> q;
		q.push(node_list[1]);
		node_list[1]->visited = true;
		Node* cur;
		Node* next;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < cur->adj_list.size(); i++) {
				next = cur->adj_list[i];
				if (!next->visited) {
					next->visited = true;
					next->height = cur->height + 1;
					q.push(next);
				}
			}
		}
	}
};

int main() {
	int n;
	cin >> n;
	Tree t(n);
	
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		t.link(a, b);
	}
	t.BFS();
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (t.node_list[i]->adj_list.size() == 1) {
			cnt += t.node_list[i]->height;
		}
	}
	if (cnt % 2 == 1)	cout << "Yes";
	else	cout << "No";
	
	return 0;
}