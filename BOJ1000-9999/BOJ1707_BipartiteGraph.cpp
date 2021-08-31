// �� ������ ������ ������ �ٸ� ���տ� �����־�� �ϹǷ�
// ������ �������� ���� ��� ������ ���� BFS�� ���鼭 �� ������ ������ �������� �ٸ� �����̶�� ǥ�ø� �Ѵ�.
// �� ������ ������ �������� Ȯ���ϸ鼭 ���� ������ ��ȣ�� �Ű��� ������ �̺� �׷����� �� �� ����.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool flag = false;

struct Node {
	int data;
	int parts;
	vector<Node*> adj_list;

	Node(int data) {
		this->data = data;
		this->parts = 0;
	}
};

class Graph {
public:
	vector<Node*> node_list;
	Graph(int v) {
		node_list.push_back(0);
		for (int i = 1; i <= v; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int a, int b) {
		node_list[a]->adj_list.push_back(node_list[b]);
		node_list[b]->adj_list.push_back(node_list[a]);
	}

	void BFS(Node* node) {
		queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			int qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				vector<Node*> adj = q.front()->adj_list;
				int p = q.front()->parts;
				q.pop();
				for (int j = 0; j < adj.size(); j++) {
					if (adj[j]->parts == 0) {
						adj[j]->parts = ((-1) * p);
						q.push(adj[j]);
					}
					else if (adj[j]->parts == p) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
	}
};

int main() {
	int testcase;
	cin >> testcase;
	while(testcase--) {
		flag = false;
		int v, e;
		cin >> v >> e;
		Graph g(v);
		int a, b;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			g.link(a, b);
		}
		for (int i = 1; i < g.node_list.size(); i++) {
			if (g.node_list[i]->parts == 0) {
				g.node_list[i]->parts = 1;
				g.BFS(g.node_list[i]);
			}
		}
		if (flag)	cout << "NO\n";
		else	cout << "YES\n";
	}
	return 0;
}