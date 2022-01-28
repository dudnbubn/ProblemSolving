#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int num;
	int depth;
	Node* parent;
	vector<Node*> children;
	Node(int num) {
		this->num = num;
		this->depth = 1;
		this->parent = nullptr;
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

	void link(int par, int chi) {
		node_list[chi]->parent = node_list[par];
		node_list[par]->children.push_back(node_list[chi]);
	}

	int getAncestor(int a, int b) {
		vector<Node*> va, vb;
		Node* cur =  node_list[a];
		while (cur->parent != nullptr) {
			va.push_back(cur);
			cur = cur->parent;
		}
		cur = node_list[b];
		while (cur->parent != nullptr) {
			vb.push_back(cur);
			cur = cur->parent;
		}
		int index_a = va.size() - 1;
		int index_b = vb.size() - 1;
		while ((index_a >= 0 && index_b >= 0) && va[index_a] == vb[index_b]) {
			index_a--;
			index_b--;
		}
		return va[index_a + 1]->num;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Tree tr(n);
		int par, chi;
		for (int i = 0; i < n - 1; i++) {
			cin >> par >> chi;
			tr.link(par, chi);
		}
		cin >> par >> chi;
		cout << tr.getAncestor(par, chi) << "\n";;
	}
	return 0;
}