// key point : 1. 하나의 노드에 대해 사이클이 생길 수 있다.
//			   2. 간선의 개수가 0 일 수 있다.

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
		if (a == b)
			node_list[a]->visited = true;
		else {
			node_list[a]->adj_list.push_back(node_list[b]);
			node_list[b]->adj_list.push_back(node_list[a]);
		}
	}

	bool BFS(int x) {
		bool result = true;
		queue<pair<Node*, int>> q;
		q.push({ node_list[x], 0 });
		node_list[x]->visited = true;
		pair<Node*, int> cur;
		Node* next;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < cur.first->adj_list.size(); i++) {
				next = cur.first->adj_list[i];
				if (next->num == cur.second)	continue;
				if (next->visited) {
					result = false;
					continue;
				}
				next->visited = true;
				q.push({ next, cur.first->num });
			}
		}
		return result;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int tc = 0;
	while (n != 0 || m != 0) {
		tc++;
		Tree t(n);
		int cnt = 0;
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			t.link(a, b);
		}

		for (int i = 1; i <= n; i++) {
			if (!t.node_list[i]->visited && t.BFS(i))
				cnt++;
		}

		cout << "Case " << tc << ": ";
		switch (cnt) {
		case 0:
			cout << "No trees.\n";	break;
		case 1:
			cout << "There is one tree.\n";	break;
		default:
			cout << "A forest of " << cnt << " trees.\n";
		}

		cin >> n >> m;
	}
	return 0;
}