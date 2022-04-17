// key point : Topological Sort

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

struct Node {
	int num;
	int relationCount;
	vector<Node*> next;
	Node(int num) {
		this->num = num;
		this->relationCount = 0;
	}
};

bool compare(Node* a, Node* b) {
	return a->num < b->num;
}

struct comp {
	bool operator()(Node* a, Node* b) {
		return a->num > b->num;
	}
};

class Graph {
public:
	vector<Node*> nodeList;
	Graph() {
		nodeList.push_back(0);
		for (int i = 1; i <= n; i++) {
			Node* newNode = new Node(i);
			nodeList.push_back(newNode);
		}
	}

	void link(int a, int b) {
		nodeList[a]->next.push_back(nodeList[b]);
		nodeList[b]->relationCount++;
	}

	void BFS() {
		priority_queue<Node*, vector<Node*>, comp> q;
		for (int i = 1; i <= n; i++) {
			sort(nodeList[i]->next.begin(), nodeList[i]->next.end(), compare);
			if (nodeList[i]->relationCount == 0)
				q.push(nodeList[i]);
		}
		Node* cur;
		while (!q.empty()) {
			cur = q.top();
			q.pop();
			cout << cur->num << " ";
			for (int i = 0; i < cur->next.size(); i++) {
				if (cur->next[i]->relationCount) {
					cur->next[i]->relationCount--;
					if (!cur->next[i]->relationCount)
						q.push(cur->next[i]);
				}
			}
		}
	}
};

int main() {
	cin >> n >> m;

	Graph g;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g.link(a, b);
	}
	g.BFS();
	return 0;
}