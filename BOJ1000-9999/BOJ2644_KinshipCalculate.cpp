// BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

struct Node {
	int data;
	int visited;
	Node* parent;
	vector<Node*> children;
	Node(int data) {
		this->data = data;
		this->visited = false;
		this->parent = NULL;
	}
};

class Tree {
public:
	vector<Node*> node_list;
	Tree(int n) {
		this->node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void insert(int par, int chi) {
		node_list[chi]->parent = node_list[par];
		node_list[par]->children.push_back(node_list[chi]);
	}

	int BFS(int n, int target) {
		int result = -1;
		queue<Node*> q;
		node_list[n]->visited = true;
		q.push(node_list[n]);
		while (!q.empty()) {
			result++;
			int qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				Node* cur = q.front();
				q.pop();
				if (cur->data == target)	return result;
				
				if (cur->parent != NULL && !cur->parent->visited) {
					cur->parent->visited = true;
					q.push(cur->parent);
				}
				for (int j = 0; j < cur->children.size(); j++) {
					if (!cur->children[j]->visited) {
						cur->children[j]->visited = true;
						q.push(cur->children[j]);
					}
				}
			}
		}
		return -1;
	}
	
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Tree t(n);
	int a, b;
	int par, chi;
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> par >> chi;
		t.insert(par, chi);
	}
	cout << t.BFS(a, b);
	return 0;
}