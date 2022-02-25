#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct Node {
	int num;
	bool visited;
	vector<Node*> light;
	vector<Node*> heavy;
	Node(int num) {
		this->num = num;
		this->visited = false;
	}
};

class Graph {
public:
	vector<Node*> node_list;
	Graph() {
		node_list.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* new_node = new Node(i);
			node_list.push_back(new_node);
		}
	}

	void link(int heavy, int light) {
		node_list[heavy]->light.push_back(node_list[light]);
		node_list[light]->heavy.push_back(node_list[heavy]);
	}

	void clear() {
		for (int i = 1; i <= n; i++)
			node_list[i]->visited = false;
	}

	bool isSide(int num) {
		clear();
		queue<Node*> q;
		int heavy = 0, light = 0;
		q.push(node_list[num]);
		node_list[num]->visited = true;
		Node* cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < cur->heavy.size(); i++) {
				if (!cur->heavy[i]->visited) {
					cur->heavy[i]->visited = true;
					q.push(cur->heavy[i]);
					heavy++;
				}
			}
		}
		q.push(node_list[num]);
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int i = 0; i < cur->light.size(); i++) {
				if (!cur->light[i]->visited) {
					cur->light[i]->visited = true;
					q.push(cur->light[i]);
					light++;
				}
			}
		}
		if (heavy > (n / 2) || light > (n / 2))	return true;
		else	return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	Graph g;
	int heavy, light;
	for (int i = 0; i < m; i++) {
		cin >> heavy >> light;
		g.link(heavy, light);
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
		if (g.isSide(i))
			result++;

	cout << result;
	return 0;
}