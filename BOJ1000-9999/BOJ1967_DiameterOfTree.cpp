#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int num;
	bool visited;
	vector<pair<Node*, int>> adj_list;
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

	void link(int a, int b, int c) {
		node_list[a]->adj_list.push_back({ node_list[b], c });
		node_list[b]->adj_list.push_back({ node_list[a], c });
	}

	void clear() {
		for (int i = 1; i < node_list.size(); i++)
			node_list[i]->visited = false;
	}

	int getDiameter() {
		int result = 0, temp;
		queue<pair<Node*, int>> q;
		pair<Node*, int> cur;
		for (int i = 1; i < node_list.size(); i++) {
			if (node_list[i]->adj_list.size() == 1) {
				clear();
				temp = 0;
				while (!q.empty())	q.pop();

				q.push({ node_list[i], 0 });
				node_list[i]->visited = true;
				while (!q.empty()) {
					cur = q.front();
					q.pop();
					temp = max(temp, cur.second);
					for (int j = 0; j < cur.first->adj_list.size(); j++) {
						if (!cur.first->adj_list[j].first->visited) {
							cur.first->adj_list[j].first->visited = true;
							q.push({ cur.first->adj_list[j].first, cur.second + cur.first->adj_list[j].second });
						}
					}
				}
				result = max(result, temp);
			}
		}
		return result;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	Tree t(n);
	int a, b, c;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a >> b >> c;
		t.link(a, b, c);
	}
	cout << t.getDiameter();
	return 0;
}