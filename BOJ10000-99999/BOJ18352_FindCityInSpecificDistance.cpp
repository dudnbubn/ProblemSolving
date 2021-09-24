#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[300001] = { 0, };
vector<int> result;
int k;

struct Node {
	int data;
	bool visited;
	vector<Node*> adj_list;
	Node(int data) {
		this->data = data;
		this->visited = false;
	}
};

class city {
public:
	vector<Node*> node_list;
	city(int n) {
		node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}
	void link(int a, int b) {
		node_list[a]->adj_list.push_back(node_list[b]);
	}

	void BFS(int n) {
		queue<Node*> q;
		int d = 0;
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
						dist[cur->adj_list[j]->data] = d;
						if (d == k)
							result.push_back(cur->adj_list[j]->data);
						q.push(cur->adj_list[j]);
					}
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> k >> x;
	city c(n);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		c.link(a, b);
	}
	c.BFS(x);

	sort(result.begin(), result.end());
	if (result.size() == 0)	cout << -1;
	else {
		for (int i : result)
			cout << i << "\n";
	}

	return 0;
}