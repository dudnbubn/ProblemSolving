// 입력으로 들어오는 숫자 쌍이 루트부터 순차적으로 연결되는 순서가 아니기 때문에
// 먼저 연결을 해놓고 루트부터 BFS를 돌아 각 노드의 부모를 알아내야한다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int parentOf[100001];

struct Node {
	int data;
	bool visited;
	vector<Node*> adj_list;
	Node(int data) {
		this->data = data;
		this->visited = false;
	}
};

class Tree {
public:
	vector<Node*> node_list;
	Node* root;

	Tree(int n) {
		node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
		this->root = node_list[1];
	}

	void link(int a, int b) {
		node_list[a]->adj_list.push_back(node_list[b]);
		node_list[b]->adj_list.push_back(node_list[a]);
	}

	void BFS() {
		queue<Node*> q;
		node_list[1]->visited = true;
		q.push(node_list[1]);
		while (!q.empty()) {
			Node* cur = q.front();
			q.pop();
			for (int i = 0; i < cur->adj_list.size(); i++) {
				if (!cur->adj_list[i]->visited) {
					cur->adj_list[i]->visited = true;
					parentOf[cur->adj_list[i]->data] = cur->data;
					q.push(cur->adj_list[i]);
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	Tree t(n);
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		t.link(a, b);
	}
	t.BFS();
	for (int i = 2; i <= n; i++)	cout << parentOf[i] << "\n";

	return 0;
}