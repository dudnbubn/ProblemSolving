#include <iostream>
#include <vector>
using namespace std;

int leaf = 0;

struct Node {
	int num;
	vector<Node*> children;
	Node(int num) {
		this->num = num;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_list;
	Tree(int n) {
		this->root = NULL;

		for (int i = 0; i < n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void setRoot(int r) {
		root = node_list[r];
	}
	
	void link(int par, int chi) {
		node_list[par]->children.push_back(node_list[chi]);
	}

	void trev(Node* node, int rm) {
		if (node->num == rm)	return;

		bool flag = true;
		for (int i = 0; i < node->children.size(); i++) {
			if (node->children[i]->num != rm) {
				flag = false;
				trev(node->children[i], rm);
			}
		}
		if (flag) leaf++;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	Tree t(n);
	int par;
	for (int i = 0; i < n; i++) {
		cin >> par;
		if (par == -1)	t.setRoot(i);
		else	t.link(par, i);
	}
	int rm;
	cin >> rm;
	t.trev(t.root, rm);
	cout << leaf;
	return 0;
}