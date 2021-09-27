#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[101] = { 0, };
int minimum = 2100000000;

struct Node {
	int data;
	bool visited;
	vector<Node*> adj_list;
	Node(int data) {
		this->data = data;
		this->visited = false;
	}
};

class User {
public:
	vector<Node*> node_list;
	User(int n) {
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

	int BFS(int n) {
		for (int i = 1; i < node_list.size(); i++)	
			node_list[i]->visited = false;
		int result = 0;
		int d = 0;
		queue<Node*> q;
		node_list[n]->visited = true;
		q.push(node_list[n]);
		while (!q.empty()) {
			d++;
			int qsz = q.size();
			for (int i = 0; i < qsz; i++) {
				Node* cur = q.front();
				q.pop();
				for (int j = 0; j < cur->adj_list.size(); j++) {
					if (!cur->adj_list[j]->visited) {
						cur->adj_list[j]->visited = true;
						result += d;
						q.push(cur->adj_list[j]);
					}
				}
			}
		}
		return result;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	User u(n);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		u.link(a, b);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = u.BFS(i);
		minimum = min(minimum, dist[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (minimum == dist[i]) {
			cout << i;
			return 0;
		}
	}
}