#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool used[16];

struct Node {
	int num;
	bool on;
	bool visited;
	Node* parent;
	vector<Node*> children;
	Node(int num) {
		this->num = num;
		this->on = false;
		this->visited = false;
		this->parent = nullptr;
	}
};

class Tree {
public:
	vector<Node*> node_list;
	Tree() {
		node_list.push_back(0);
		for (int i = 1; i <= 15; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void clear() {
		for (int i = 1; i <= 15; i++) {
			node_list[i]->on = false;
			node_list[i]->parent = nullptr;
			node_list[i]->visited = false;
			node_list[i]->children = {};
		}
	}

	bool link(int u, int v) {
		if (node_list[v]->parent != nullptr)	return false;
		node_list[u]->children.push_back(node_list[v]);
		node_list[v]->parent = node_list[u];
		node_list[u]->on = true;
		node_list[v]->on = true;
		return true;
	}

	bool check() {
		Node* root = nullptr;
		for (int i = 1; i <= 15; i++) {
			if (node_list[i]->on && node_list[i]->parent == nullptr && node_list[i]->children.size() != 0)
				root = node_list[i];
		}
		
		queue<Node*> q;
		q.push(root);
		root->visited = true;
		Node* cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < cur->children.size(); i++) {
				if (cur->children[i]->visited)	return false;
				cur->children[i]->visited = true;
				q.push(cur->children[i]);
			}
		}

		for (int i = 1; i <= 15; i++) {
			if (node_list[i]->on && !node_list[i]->visited)
				return false;
		}

		return true;
	}
};

int main() {
	int u, v;
	Tree t;

	int tc = 0;

	while (1) {
		tc++;
		for (int i = 1; i <= 15; i++)	used[i] = false;
		int ver_cnt = 0, edg_cnt = 0;
		cin >> u >> v;
		t.clear();
		while (u > 0 && v > 0) {
			t.link(u, v);
			edg_cnt++;
			if (!used[u]) {
				used[u] = true;
				ver_cnt++;
			}
			if (!used[v]) {
				used[v] = true;
				ver_cnt++;
			}
			cin >> u >> v;
		}
		if (u == -1)	break;
		if (ver_cnt == 0)	cout << "Case " << tc << " is a tree.\n";
		else if (ver_cnt != edg_cnt + 1)	cout << "Case " << tc << " is not a tree.\n";
		else {
			if(t.check())	cout << "Case " << tc << " is a tree.\n";
			else	cout << "Case " << tc << " is not a tree.\n";
		}
	}
	return 0;
}