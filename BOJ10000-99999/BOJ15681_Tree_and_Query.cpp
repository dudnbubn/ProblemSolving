#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int num;
	int children;
	Node* parent;
	vector<Node*> adj_list;
	Node(int num) {
		this->num = num;
		this->children = 1;
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

	void noticeParent(Node* node) {
		for (int i = 0; i < node->adj_list.size(); i++) {
			if (node->adj_list[i] == node->parent)	continue;
			node->adj_list[i]->parent = node;
			noticeParent(node->adj_list[i]);
		}
	}

	void countSubtreeNodes(Node* cur) {
		for (int i = 0; i < cur->adj_list.size(); i++) {
			if (cur->adj_list[i] == cur->parent)	continue;
			countSubtreeNodes(cur->adj_list[i]);
			cur->children += cur->adj_list[i]->children;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;
	int u, v;
	Tree t(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		t.link(u, v);
	}
	t.noticeParent(t.node_list[r]);
	t.countSubtreeNodes(t.node_list[r]);

	int x;
	for (int i = 0; i < q; i++) {
		cin >> x;
		cout << t.node_list[x]->children << "\n";
	}
	return 0;
}